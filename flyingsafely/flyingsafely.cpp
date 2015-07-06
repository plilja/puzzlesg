#include "minspantree.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<pair<pair<int, int>, double>> edges;
        for (int j = 0; j < m; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; //make zero indexed
            b--;
            edges.push_back({{a, b}, 1.0});
        }
        auto r = prim(edges, n);
        printf("%d\n", (int)r.total_cost);
    }
}
