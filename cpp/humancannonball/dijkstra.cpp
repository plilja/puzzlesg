#include "dijkstra.h"
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::priority_queue;
using std::pair;

Dijkstra::Dijkstra(size_t n, const vector <pair<pair<int, int>, double>> &edges, int s) : source(s), nr_of_nodes(n)
{
    parent = vector<int>(n, -1);
    dist = vector<double>(n, -1);
    adj_list = vector < vector < pair<int, double>>>(n);
    for (auto p : edges) {
        adj_list[p.first.first].push_back({p.first.second, p.second});
    }
    construct();
}


double Dijkstra::distance(int goal)
{
    return dist[goal];
}

vector<int> Dijkstra::getPath(int goal)
{
    vector<int> ans;
    if (dist[goal] == -1) {
        return ans; //no path, return empty list
    }
    int n = goal;
    while (n != source) {
        if (n == -1) {
            //ERROR
            ans.clear();
            return ans;
        }
        ans.push_back(n);
        n = parent[n];
    }
    ans.push_back(source);
    reverse(ans.begin(), ans.end());
    return ans;
}

void Dijkstra::construct()
{
    typedef pair<double, pair<int, int>> QueueItem;

    priority_queue <QueueItem, vector<QueueItem>, std::greater<QueueItem>> pq;
    vector<bool> visited(nr_of_nodes, false);

    dist[source] = 0;
    pq.push({0, {-1, source}});

    pair<double, int> p;
    while (!pq.empty()) {
        auto qi = pq.top();
        pq.pop();

        double d = qi.first;
        int from = qi.second.first;
        int to = qi.second.second;

        if (visited[to])
            continue;
        visited[to] = true;

        parent[to] = from;
        dist[to] = d;

        for (auto neighbour : adj_list[to]) {
            if (visited[neighbour.first]) {
                continue;
            }
            pq.push({d + neighbour.second, {to, neighbour.first}});
        }
    }
}

