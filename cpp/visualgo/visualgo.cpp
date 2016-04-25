#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

int dijkstra(vector<vector<edge>> &graph, int V, int s, int t) {
    priority_queue<pair<int, pair<int, int>>> q;
    vector<bool> visited(V, false);
    visited[s] = true;
    vector<int> count(V, 0);
    vector<int> dist(V);
    dist[s] = 0;
    count[s] = 1;

    for (auto e : graph[s]) {
        q.push({-e.second, {s, e.first}});
    }

    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int to = p.second.second;
        int d = -p.first;
        int from = p.second.first;

        if (visited[to]) {
            if (d == dist[to]) {
                count[to] += count[from];
            }
            continue;
        }

        visited[to] = true;
        count[to] = count[from];
        dist[to] = d;

        for (auto e : graph[to]) {
            q.push({-d - e.second, {to, e.first}});
        }
    }
    return count[t];
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    vector<vector<edge>> graph(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }
    int s, t;
    scanf("%d %d", &s, &t);

    int r = dijkstra(graph, V, s, t);

    printf("%d\n", r);
}


