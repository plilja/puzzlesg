#include "segmentintersection.h"
#include <cmath>
#include <algorithm>
#include <limits>

using std::pair;

const double EPS = 10e-8;

struct LineEq {
    double a, b, c;
};

inline double x(pair<double, double> &p)
{
    return p.first;
}

inline double y(pair<double, double> &p)
{
    return p.second;
}

inline LineEq lineEq(Line &line)
{
    double a = y(line.p2) - y(line.p1);
    double b = x(line.p1) - x(line.p2);
    double c = a * x(line.p1) + b * y(line.p1);
    return LineEq({a, b, c});
}

/**
 * Helper function to easily be able to determine how two parallell lines relates
 * to each other.
 */
inline double projectToDouble(Line &line, pair<double, double> &pointOnLine)
{
    auto eq = lineEq(line);
    if (fabs(eq.b) < EPS) {
        return y(pointOnLine);
    } else {
        return x(pointOnLine);
    }
}

inline bool samePoint(pair<double, double> &p1, pair<double, double> &p2)
{
    return fabs(x(p1) - x(p2)) < EPS &&
           fabs(y(p1) - y(p2)) < EPS;
}

inline LineSegmentIntersectResult lineIntersects(pair<double, double> &p1, pair<double, double> &p2)
{
    if (samePoint(p1, p2))
        return LineSegmentIntersectResult({SINGLE_POINT, p1, {0, 0}});
    else
        return LineSegmentIntersectResult({LINE, p1, p2});
}

inline LineSegmentIntersectResult noIntersection()
{
    return LineSegmentIntersectResult({NONE, {0, 0}, {0, 0}});
}

inline Line withLeftMostPointFirst(Line &line)
{
    if (x(line.p1) < x(line.p2) - EPS ||
        (fabs(x(line.p1) - x(line.p2)) < EPS && y(line.p1) < y(line.p2) - EPS))
        return line;
    else
        return Line({line.p2, line.p1});
}

LineSegmentIntersectResult segmentIntersectionOfEqualLinesWithDifferentEndPoints(Line &line1, Line &line2)
{
    double line1Left = projectToDouble(line1, line1.p1);
    double line2Left = projectToDouble(line2, line2.p1);
    double line1Right = projectToDouble(line1, line1.p2);
    double line2Right = projectToDouble(line2, line2.p2);
    if (line1Left < line2Left + EPS) {
        if (line1Right > line2Right) {
            return lineIntersects(line2.p1, line2.p2);
        } else if (line1Right > line2Left - EPS) {
            return lineIntersects(line2.p1, line1.p2);
        } else {
            return noIntersection();
        }
    } else {
        return segmentIntersectionOfEqualLinesWithDifferentEndPoints(line2, line1);
    }
}

bool pointIsOnLine(pair<double, double> &p, Line &line)
{
    auto eq = lineEq(line);
    bool on_infinite_line = fabs(eq.a * x(p) + eq.b * y(p) - eq.c) < EPS;
    bool between_endpoints = x(p) > std::min(x(line.p1), x(line.p2)) - EPS && y(p) > std::min(y(line.p1), y(line.p2)) - EPS &&
                             x(p) < std::max(x(line.p1), x(line.p2)) + EPS && y(p) < std::max(y(line.p1), y(line.p2)) + EPS;
    return on_infinite_line && between_endpoints;
}

LineSegmentIntersectResult segmentIntersection(Line line1, Line line2)
{
    line1 = withLeftMostPointFirst(line1);
    line2 = withLeftMostPointFirst(line2);

    if (samePoint(line1.p1, line1.p2) && samePoint(line2.p1, line2.p2)) {
        if (samePoint(line1.p1, line2.p1)) {
            return LineSegmentIntersectResult({SINGLE_POINT, line1.p1, {0, 0}});
        } else {
            return noIntersection();
        }
    } else if (samePoint(line1.p1, line1.p2)) {
        if (pointIsOnLine(line1.p1, line2)) {
            return LineSegmentIntersectResult({SINGLE_POINT, line1.p1, {0, 0}});
        } else {
            return noIntersection();
        }
    } else if (samePoint(line2.p1, line2.p2)) {
        return segmentIntersection(line2, line1);
    }

    auto eq1 = lineEq(line1);
    auto eq2 = lineEq(line2);

    double det = eq1.a * eq2.b - eq2.a * eq1.b;

    if (fabs(det) < EPS) {
        if (fabs(eq1.b) < EPS && fabs(eq2.b) < EPS && fabs(x(line1.p1) - x(line2.p1)) > EPS)
            return noIntersection();
        if (fabs(eq1.c / eq1.b - eq2.c / eq2.b) > EPS) {
            return noIntersection();
        }
        return segmentIntersectionOfEqualLinesWithDifferentEndPoints(line1, line2);
    } else {
        double x = (eq2.b * eq1.c - eq1.b * eq2.c) / det;
        double y = (eq1.a * eq2.c - eq2.a * eq1.c) / det;
        pair<double, double> p = {x, y};
        if (!pointIsOnLine(p, line1) || !pointIsOnLine(p, line2)) {
            return noIntersection();
        } else {
            return LineSegmentIntersectResult({SINGLE_POINT, p, {0, 0}});
        }
    }
}

