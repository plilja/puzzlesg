#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &g, int a, vector<bool> &pub, vector<bool> &v) {
    for (int b : g[a]) {
        if (!v[b]) {
            v[b] = true;
            pub[b] = !pub[a];
            dfs(g, b, pub, v);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool impossible = false;
    vector<bool> pub(n);
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i) {
        if (g[i].empty()) {
            impossible = true;
        } else if (!v[i]) {
            pub[i] = true;
            dfs(g, i, pub, v);
        }
    }
    if (!impossible) {
        for (int i = 0; i < n; ++i) {
            if (pub[i]) {
                printf("pub");
            } else {
                printf("house");
            }
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        puts("Impossible");
    }
}
