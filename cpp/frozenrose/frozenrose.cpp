#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int solve(vector<vector<pii>> &g, int i, vector<bool> &v) {
    v[i] = true;
    int r = 0;
    for (auto &e : g[i]) {
        if (!v[e.first]) {
            int b;
            if (g[e.first].size() == 1) {
                b = e.second;
            } else {
                b = min(e.second, solve(g, e.first, v));
            }
            r += b;
        }
    }
    return r;
}

int main()
{
    int n, c;
    while (2 == scanf("%d %d", &n, &c)) {
        c--;
        vector<vector<pii>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--;
            v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vector<bool> v(n, false);
        int r = solve(g, c, v);
        printf("%d\n", r);
    }
}
