#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

const double INF = numeric_limits<double>::infinity();

int main() {
    int n, m, e;
    scanf("%d %d %d", &n, &m, &e);

    vector<vector<double>> g(n, vector<double>(n, INF));
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        g[a - 1][b - 1] = l;
        g[b - 1][a - 1] = l;
    }
    vector<int> exits;
    for (int i = 0; i < e; ++i) {
        int t;
        scanf("%d", &t);
        exits.push_back(t - 1);
    }
    int b, p;
    scanf("%d %d", &b, &p);
    b--;
    p--;

    // Deduce police distance to every intersection
    vector<double> police_dist(n, INF);
    {
        priority_queue<pair<double, int>> pq;
        vector<bool> visited(n, false);
        pq.push({-0.0, p});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            double d = -p.first;
            int to = p.second;

            if (visited[to]) {
                continue;
            }
            visited[to] = true;
            police_dist[to] = d;
            for (int i = 0; i < n; ++i) {
                if (!std::isinf(g[to][i])) {
                    pq.push({-d - g[to][i], i});
                }
            }
        }
    }

    // Deduce brothers minimum speed at each intersection
    vector<double> brothers_speed(n, INF);
    {
        priority_queue<pair<double, pair<double, int>>> pq;
        vector<bool> visited(n, false);
        pq.push({-0.0, {0.0, b}});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            double speed = -p.first;
            double dist = p.second.first;
            int to = p.second.second;

            if (visited[to]) {
                continue;
            }
            visited[to] = true;
            brothers_speed[to] = speed;
            for (int i = 0; i < n; ++i) {
                if (!std::isinf(g[to][i])) {
                    double police_time = police_dist[i] / 160.0;
                    double new_dist = dist + g[to][i];
                    double s = max(speed, new_dist / police_time);
                    pq.push({-s, {new_dist, i}});
                }
            }
        }
    }

    auto best = INF;
    for (auto i : exits) {
        best = min(best, brothers_speed[i]);
    }

    if (!std::isinf(best)) {
        printf("%.10lf\n", best);
    } else {
        puts("IMPOSSIBLE");
    }
}

