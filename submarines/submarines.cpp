#include "segmentintersection.h"
#include "pointinpolygon.h"
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

using namespace std;

/*double EPS = 0.0000001;

bool same_point(pair<double, double> p1, pair<double, double> p2)
{
    return fabs(p1.first - p2.first) < EPS &&
           fabs(p1.second - p2.second) < EPS;
}

bool isEndpoint(Line &line, pair<double, double> p)
{
    return same_point(line.p1, p) || same_point(line.p2, p);
}*/

int main()
{
    int n;
    scanf("%d", &n);
    vector<Line> submarines;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        submarines.push_back(Line({{x1, y1}, {x2, y2}}));
    }
    int m;
    scanf("%d", &m);
    vector<vector<Line>> islands(m, vector<Line>());
    vector<vector<pair<int, int>>> island_points(m, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int p;
        scanf("%d", &p);
        for (int j = 0; j < p; ++j) {
            int x, y;
            scanf("%d %d", &x, &y);
            island_points[i].push_back({x, y});
        }
        for (int j = 1; j <= p; ++j) {
            islands[i].push_back(Line({island_points[i][j - 1], island_points[i][j % p]}));
        }
    }
    for (int i = 0; i < n; ++i) {
        auto &sub = submarines[i];
        bool both_land_and_water = false;
        for (int j = 0; j < m; ++j) {
            auto &island = islands[j];
            for (auto &poly_line : island) {
                auto r = segmentIntersection(sub, poly_line);
                if (r.result_type != NONE) {
                    both_land_and_water = true;
                    break;
                }
            }
            if (both_land_and_water) {
                break;
            }
        }
        if (both_land_and_water) {
            printf("Submarine %d is partially on land.\n", i + 1);
        } else {
            bool land = false;
            for (auto &ipoints : island_points) {
                pair<int, int> p = {sub.p1.first, sub.p1.second};
                auto r = pointinpoly(p, ipoints);
                assert(r != ON); // this should be caught in the both_land_and_water-branch
                if (r == IN) {
                    land = true;
                    break;
                }
            }
            if (land)
                printf("Submarine %d is completely on land.\n", i + 1);
            else
                printf("Submarine %d is still in water.\n", i + 1);
        }

    }

}

