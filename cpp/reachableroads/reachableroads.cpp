#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solve(int m, vector<vector<int>> &graph) {
    set<int> unvisited;
    for (int i = 0; i < m; ++i) {
        unvisited.insert(i);
    }
    int ans = 0;
    queue<int> q;
    while (!unvisited.empty()) {
        int t = *unvisited.begin();
        unvisited.erase(t);
        q.push(t);
        ans += 1;
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            for (int neighbour : graph[next]) {
                if (unvisited.count(neighbour) > 0) {
                    unvisited.erase(neighbour);
                    q.push(neighbour);
                }
            }
        }
    }
    return ans - 1; // -1 for the first endpoint
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        int r;
        scanf("%d", &r);
        vector<vector<int>> graph(m);
        for (int i = 0; i < r; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans = solve(m, graph);
        printf("%d\n", ans);
    }
}
