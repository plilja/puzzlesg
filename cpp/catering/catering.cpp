#include <iostream>
#include <vector>
#include <cassert>
#include "fordfulkerson.h"
#include "indexmap.h"

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<CostFlowEdge> graph;
    Indexmap<int> idx;
    int source = idx.getIndex(n + 1);
    int sink = idx.getIndex(n + 2);
    int office = idx.getIndex(n + 3);
    graph.push_back(CostFlowEdge({source, office, k, 0}));
    for (int i = 1; i <= n; ++i) {
        // From office location to different sites
        long long m;
        scanf("%lld", &m);
        graph.push_back(CostFlowEdge({office, idx.getIndex(i), 1, m}));
    }
    for (int i = 1; i < n; ++i) {
        // From sites to other sites
        for (int j = 1; j <= n - i; ++j) {
            long long m;
            scanf("%lld", &m);
            graph.push_back(CostFlowEdge({idx.getIndex(-i), idx.getIndex(i + j), 1, m}));
        }
    }
    for (int i = 1; i <= n; ++i) {
        graph.push_back(CostFlowEdge({source, idx.getIndex(-i), 1, 0}));
        graph.push_back(CostFlowEdge({idx.getIndex(i), sink, 1, 0}));
    }
    auto res = minCostMaxFlow(graph, idx.size(), source, sink);
    printf("%lld\n", res.cost);
}
