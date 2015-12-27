#pragma once

#include <utility>

struct Line {
    std::pair<double, double> p1;
    std::pair<double, double> p2;
};

enum LineSegmentIntersectResultType {
    NONE, SINGLE_POINT, LINE
};

struct LineSegmentIntersectResult {
    LineSegmentIntersectResultType result_type;
    std::pair<double, double> p1; //will not store anything useful if result_type is NONE
    std::pair<double, double> p2; //will not store anything useful if result_type is NONE or SINGLE_POINT
};

/**
 * Find the intersection between two lines (if an intersection exists).
 */
LineSegmentIntersectResult segmentIntersection(Line line1, Line line2);

