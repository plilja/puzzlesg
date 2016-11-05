#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<long long>> squawk(2, vector<long long>(n, 0));
    squawk[0][s] = 1;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < n; ++j) {
            auto &squawks = squawk[(i - 1) % 2][j];
            for (int neighbour : g[j]) {
                squawk[i % 2][neighbour] += squawks;
            }
            squawks = 0;
        }
    }
    long long r = 0;
    for (auto d : squawk[t % 2]) {
        r += d;
    }
    printf("%lld\n", r);
}
