#include "segmentintersection.h"
#include "pointinpolygon.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 999;

bool same(double a, double b)
{
    return fabs(a - b) < 0.00000001;
}

bool same_point(pair<int, int> a, pair<double, double> b)
{
    return same(a.first, b.first) && same(a.second, b.second);
}

bool cmp_line_by_first_x(const Line &l1, const Line &l2)
{
    if (l1.p1.first == l2.p1.first)
        return l1.p1.second < l2.p1.second;
    return l1.p1.first < l2.p1.first;
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        vector<pair<int, int>> vertices;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            vertices.push_back({2 * x, 2 * y});
        }
        int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
        for (auto v : vertices) {
            minx = min(minx, v.first);
            maxx = max(maxx, v.first);
            miny = min(miny, v.second);
            maxy = max(maxy, v.second);
        }
        vector<Line> poly_lines;
        for (int i = 1; i < n; ++i) {
            if (vertices[i - 1].first < vertices[i].first)
                poly_lines.push_back(Line({vertices[i - 1], vertices[i]}));
            else
                poly_lines.push_back(Line({vertices[i], vertices[i - 1]}));
        }
        sort(poly_lines.begin(), poly_lines.end(), cmp_line_by_first_x);

        int ans = 0;
        for (int y = miny; y <= maxy - 2; y += 2) {
            for (int x = minx; x <= maxx - 2; x += 2) {

                // check if each corner in the square is in or on polygon
                auto tl = pointinpoly({x, y}, vertices);
                if (tl == OUT)
                    continue;
                auto bl = pointinpoly({x, y + 2}, vertices);
                if (bl == OUT)
                    continue;
                auto tr = pointinpoly({x + 2, y}, vertices);
                if (tr == OUT)
                    continue;
                auto br = pointinpoly({x + 2, y + 2}, vertices);
                if (br == OUT)
                    continue;

                int num_on = tl == ON ? 1 : 0;
                num_on += bl == ON ? 1 : 0;
                num_on += tr == ON ? 1 : 0;
                num_on += br == ON ? 1 : 0;

                // Check if square is enclosed in a pocket
                // For example, we dont want to count square at (1,0) below:
                // |~~~~~|
                // |_/|__|
                if (num_on >= 3) {
                    auto middle_top = pointinpoly({x + 1, y}, vertices);
                    if (middle_top == OUT)
                        continue;
                    auto middle_right = pointinpoly({x + 2, y + 1}, vertices);
                    if (middle_right == OUT)
                        continue;
                    auto middle_bottom = pointinpoly({x + 1, y + 2}, vertices);
                    if (middle_bottom == OUT)
                        continue;
                    auto middle_left = pointinpoly({x, y + 1}, vertices);
                    if (middle_left == OUT)
                        continue;
                }

                // Check if the edges of the square intersect any part of the polygon
                bool intersects = false;
                for (auto &poly_line : poly_lines) {
                    if (poly_line.p1.first > x + 2)
                        break;

                    auto r = segmentIntersection(Line({{x, y}, {x + 2, y}}), poly_line);
                    if (r.result_type == SINGLE_POINT && !same_point({x, y}, r.p1) && !same_point({x + 2, y}, r.p1)) {
                        intersects = true;
                        break;
                    }
                    r = segmentIntersection(Line({{x + 2, y}, {x + 2, y + 2}}), poly_line);
                    if (r.result_type == SINGLE_POINT && !same_point({x + 2, y}, r.p1) && !same_point({x + 2, y + 2}, r.p1)) {
                        intersects = true;
                        break;
                    }
                    r = segmentIntersection(Line({{x, y + 2}, {x + 2, y + 2}}), poly_line);
                    if (r.result_type == SINGLE_POINT && !same_point({x, y + 2}, r.p1) && !same_point({x + 2, y + 2}, r.p1)) {
                        intersects = true;
                        break;
                    }
                    r = segmentIntersection(Line({{x, y}, {x, y + 2}}), poly_line);
                    if (r.result_type == SINGLE_POINT && !same_point({x, y}, r.p1) && !same_point({x, y + 2}, r.p1)) {
                        intersects = true;
                        break;
                    }
                }

                if (!intersects)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }

}
