#include <vector>
#include "minspantree.h"
#include <queue>
#include <algorithm>

using std::vector;
using std::pair;
using std::priority_queue;

inline pair<int, int> smallestFirst(pair<int, int> &p)
{
    return {std::min(p.first, p.second), std::max(p.first, p.second)};
}

template <typename T>
priority_queue<T, vector<T>, std::greater<T>> reversePriorityQueue()
{
    return priority_queue<T, vector<T>, std::greater<T>>();
}

SpanningTree prim(vector<pair<pair<int, int>, double>> &edges, int nr_of_nodes)
{
    vector<vector<pair<int, double>>> adj_list(nr_of_nodes);
    for (auto &edge : edges) {
        adj_list[edge.first.first].push_back({edge.first.second, edge.second});
        adj_list[edge.first.second].push_back({edge.first.first, edge.second});
    }

    vector<pair<int, int>> tree_edges;
    double tree_edges_cost = 0;
    vector<bool> visited(nr_of_nodes, false);
    auto pq = reversePriorityQueue<pair<double, pair<int, int>>>();

    pq.push({0.0, { -1, 0}});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if (visited[p.second.second]) {
            continue;
        }

        visited[p.second.second] = true;
        tree_edges_cost += p.first;
        if (p.second.first != -1)
            tree_edges.push_back(smallestFirst(p.second));

        for (auto &neighbour : adj_list[p.second.second]) {
            if (!visited[neighbour.first]) {
                pq.push({neighbour.second, {p.second.second, neighbour.first}});
            }
        }
    }
    bool valid = (int)tree_edges.size() == nr_of_nodes - 1;
    return SpanningTree({valid, tree_edges, tree_edges_cost});
}
