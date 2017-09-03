#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, pair<int, int>> Key;

bool solve(vector<bool> &wall, int c1, int c2, int c3, int x, map<Key, bool> &cache) {
    if (wall.size() - 1 == x) {
        return true;
    }
    Key key = {c1, {c2, c3}};
    auto it = cache.find(key);
    if (cache.end() != it) {
        return it->second;
    }
    bool b = false;
    if (wall.size() > x + 1 && c1 > 0 && !wall[x + 1]) {
        b = b || solve(wall, c1 - 1, c2, c3, x + 1, cache);
    }
    if (wall.size() > x + 2 && c2 > 0 && !wall[x + 2]) {
        b = b || solve(wall, c1, c2 - 1, c3, x + 2, cache);
    }
    if (wall.size() > x + 3 && c3 > 0 && !wall[x + 3]) {
        b = b || solve(wall, c1, c2, c3 - 1, x + 3, cache);
    }
    cache[key] = b;
    return b;
}

int main()
{
    int n, c1, c2, c3;
    scanf("%d %d %d %d", &n, &c1, &c2, &c3);
    vector<bool> wall;
    for (int i = 0; i < n; ++i) {
        int brick;
        scanf("%d", &brick);
        for (int j = 0; j < brick - 1; ++j) {
            wall.push_back(false);
        }
        bool is_last = i == n - 1;
        wall.push_back(!is_last);
    }
    map<Key, bool> cache;
    if (solve(wall, c1, c2, c3, -1, cache)) {
        puts("YES");
    } else {
        puts("NO");
    }
}
