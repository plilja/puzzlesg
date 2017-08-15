#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;

int INF = 200 * 100 * 2 + 1;

int solve(vector<vector<int>> &gallery, int n, int k, int i, int j, map<pair<pii, int>, int> &cache) {
    if (k == 0) {
        return 0;
    }
    if (n == i) {
        return INF;
    }
    pair<pii, int> key = {{k, i}, j};
    auto it = cache.find(key);
    if (it != cache.end()) {
        return it->second;
    }
    int a = solve(gallery, n, k, i + 1, j, cache);
    int b = solve(gallery, n, k, i + 1, (j + 1) % 2, cache);
    int c = solve(gallery, n, k - 1, i + 1, j, cache) + gallery[i][(j + 1) % 2];
    int ans = min(a, min(b, c));
    cache[key] = ans;
    return ans;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<vector<int>> gallery(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &gallery[i][0], &gallery[i][1]);
    }
    int sum = 0;
    for (auto v : gallery) {
        for (int i : v) {
            sum += i;
        }
    }
    map<pair<pii, int>, int> cache;
    int cost = min(solve(gallery, n, k, 0, 0, cache), solve(gallery, n, k, 0, 1, cache));
    int ans = sum - cost;
    printf("%d\n", ans);
}
