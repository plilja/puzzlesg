#include <iostream>
#include <map>

using namespace std;

int solve(int n, int steps, int x, int y, map<pair<int, pair<int, int>>, int> &cache) {
    if (steps == n) {
        if (x == 0 && y == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    pair<int, pair<int, int>> key = {steps, {x, y}};
    auto it = cache.find(key);
    if (it != cache.end()) {
        return it->second;
    }
    int r = solve(n, steps + 1, x - 1, y - 1, cache) +
            solve(n, steps + 1, x, y - 1, cache) +
            solve(n, steps + 1, x - 1, y, cache) +
            solve(n, steps + 1, x + 1, y, cache) +
            solve(n, steps + 1, x, y + 1, cache) +
            solve(n, steps + 1, x + 1, y + 1, cache);
    cache[key] = r;
    return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        map<pair<int, pair<int, int>>, int> cache;
        int r = solve(n, 0, 0, 0, cache);
        printf("%d\n", r);
    }
}