#include "pointinpolygon.h"
#include <vector>

using std::vector;
using std::pair;

int crossProduct(const pair<int, int> &x, const pair<int, int> &y, const pair<int, int> &z)
{
    return (y.first - x.first) * (z.second - x.second) -
           (z.first - x.first) * (y.second - x.second);
}

PointInPolyResult pointinpoly(pair<int, int> p, const vector<pair<int, int>> &poly)
{
    if (poly.size() == 0) {
        return OUT;
    } else if (poly.size() == 1) {
        if (p == poly[0])
            return ON;
        return OUT;
    }

    PointInPolyResult res = OUT;

    int num_points = poly.size();
    auto p1 = poly[0];
    for (int i = 1; i <= num_points; ++i) {
        auto p2 = poly[i % num_points];
        if (p2 == p1)
            continue; //ignore duplicate consecutives

        int cross_prod = crossProduct(p, p1, p2);
        if (p1.second < p2.second)
            cross_prod = crossProduct(p, p1, p2);
        else
            cross_prod = crossProduct(p, p2, p1);
        if (p.second >= std::min(p1.second, p2.second) &&
            p.second <= std::max(p1.second, p2.second) &&
            p.first <= std::max(p1.first, p2.first)) {
            if (cross_prod == 0 && p.first >= std::min(p1.first, p2.first)) {
                res = ON;
            }
            if (cross_prod > 0 && p.second != std::min(p1.second, p2.second)) {
                if (res == IN)
                    res = OUT;
                else if (res == OUT)
                    res = IN;
            }
        }
        p1 = p2;
    }
    return res;
}

