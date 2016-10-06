#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e8;

int solve(vector<vector<pair<int, int>>> &graph, int n, vector<int> &george_route, int a, int b, int k)
{
    vector<vector<int>> george_arrival(n, vector<int>(n, INF));
    int t = 0;
    for (int i = 1; i < george_route.size(); ++i) {
        int from = george_route[i - 1];
        int to = george_route[i];
        george_arrival[from][to] = t;
        george_arrival[to][from] = t;
        for (auto &edge : graph[from]) {
            if (edge.first == to) {
                t += edge.second;
                break;
            }
        }
    }
    set<pair<int, int>> q;
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);
    q.insert({k, a});
    while (!q.empty() && !visited[b]) {
        auto front = *q.begin();
        q.erase(q.begin());

        int time = front.first;
        int intersection = front.second;
        if (visited[intersection]) {
            continue;
        }
        visited[intersection] = true;
        dist[intersection] = time;
        for (auto &edge : graph[intersection]) {
            int possible_arrival = time + edge.second;
            int ga = george_arrival[intersection][edge.first];
            if (time >= ga &&
                    time <= ga + edge.second) {
                possible_arrival = ga + 2 * edge.second;
            }
            q.insert({possible_arrival, edge.first});
        }
    }
    return dist[b] - k;
}

int main()
{
    int n, m, a, b, k, g;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &k, &g);
    a--; // make zero indexed
    b--;
    vector<int> george_route;
    for (int i = 0; i < g; ++i) {
        int d;
        scanf("%d", &d);
        d--; // make zero indexed
        george_route.push_back(d);
    }
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int fr, to, dist;
        scanf("%d %d %d", &fr, &to, &dist);
        fr--; // make zero indexed
        to--;
        graph[fr].push_back({to, dist});
        graph[to].push_back({fr, dist});
    }
    int ans = solve(graph, n, george_route, a, b, k);
    printf("%d\n", ans);
}
