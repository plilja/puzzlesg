#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solve(vector<vector<int>> &g, int n) {
    queue<int> q;
    q.push(0);
    vector<bool> v(n, false);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        if (v[a]) {
            continue;
        }
        v[a] = true;
        for (int b : g[a]) {
            q.push(b);
        }
    }
    vector<int> r;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            r.push_back(i);
        }
    }
    return r;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // make zero indexed
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> unconnected = solve(g, n);
    if (unconnected.empty()) {
        printf("Connected\n");
    } else {
        for (int h : unconnected) {
            printf("%d\n", h + 1);
        }
    }
}



