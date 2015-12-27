#include <iostream>
#include <vector>
#include <cmath>
#include "minspantree.h"

using namespace std;

typedef pair<double, double> point;

int main()
{
    int n;
    scanf("%d", &n);
    for (int t = 0; t < n; ++t) {
        int m;
        scanf("%d", &m);
        vector<point> islands(m);
        for (int i = 0; i < m; ++i) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            islands[i] = {x, y};
        }
        vector<pair<pair<int, int>, double>> edges;
        for (int i = 0; i < m; ++i)
        {
            auto &p1 = islands[i];
            for (int j = 0; j < m; ++j)
            {
                auto &p2 = islands[j];
                double d = sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
                edges.push_back({{i, j}, d});
            }
        }
        auto r = prim(edges, m);
        printf("%.2lf\n", r.total_cost);
    }
}
