#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "minspantree.h"

using namespace std;

typedef pair<int, int> pii;

double dist(pii a, pii b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int _ = 0; _ < n; ++_) {
        int s, p;
        scanf("%d %d", &s, &p);
        vector<pii> op(p);
        for (int i = 0; i < p; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            op[i] = {x, y};
        }
        
        double ans;
        if (p <= s) {
            // Every outpost communicates via satellite
            ans = 0;
        } else {
            // Find min span tree
            vector<pair<pii, double>> graph;
            for (int i = 0; i < p; ++i) {
                for (int j = i + 1; j < p; ++j) {
                    double d = dist(op[i], op[j]);
                    graph.push_back({{i, j}, d});
                }
            }
            auto mst = prim(graph, p);

            // Sort edges in min span tree by dist
            vector<double> dists;
            for (pii edge : mst.edges) {
                double d = dist(op[edge.first], op[edge.second]);
                dists.push_back(d);
            }
            sort(dists.begin(), dists.end());
            if (s > 1) {
                ans = dists[dists.size() - s];
            } else {
                ans = dists[dists.size() - 1];
            }
        }

        printf("%.2f\n", ans);
    }
}
