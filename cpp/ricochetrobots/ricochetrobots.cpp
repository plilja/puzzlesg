#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii directions[] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

ll encode(vector<pair<pii, int>> &robots) {
    ll res = 0;
    for (auto &r : robots) {
        res <<= 4;
        res |= r.first.first;
        res <<= 4;
        res |= r.first.second;
        res <<= 4;
        res |= r.second;
    }
    return res;
}

int solve(vector<vector<char>> &grid, vector<pair<pii, int>> &initial_robots, int n, int w, int h, int l, int targetX, int targetY) {

    queue<pair<vector<pair<pii, int>>, int>> q;
    set<ll> vis;
    vis.insert(encode(initial_robots));
    q.push({initial_robots, 0});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int dist = t.second;
        if (dist > l) {
            return -1;
        }
        auto &robots = t.first;
        for (auto &r : robots) {
            if (r.first.second == targetY && r.first.first == targetX && r.second == 1) {
                return dist;
            }
        }
        for (auto &r : robots) {
            grid[r.first.second][r.first.first] = 'W'; // Mark robot positions as walls temporarily
        }
        for (int i = 0; i < 4; ++i) {
            auto d = directions[i];
            for (int j = 0; j < n; ++j) {
                auto r = robots[j];
                int k = 1;
                while (
                    r.first.second + k * d.second >= 0 &&
                    r.first.second + k * d.second < h &&
                    r.first.first + k * d.first >= 0 &&
                    r.first.first + k * d.first < w &&
                    grid[r.first.second + k * d.second][r.first.first + k * d.first] == '.') {
                    k++;
                }
                k--; // We've stepped one step to far
                if (k > 0 && dist + 1 <= l) {
                    robots[j] = {{r.first.first + k * d.first, r.first.second + k * d.second}, r.second};
                    ll key = encode(robots);
                    if (vis.count(key) == 0) {
                        vis.insert(key);
                        q.push({robots, dist + 1});
                    }
                    robots[j] = {{r.first.first, r.first.second}, r.second};
                }
            }
        }
        for (auto &r : robots) {
            grid[r.first.second][r.first.first] = '.'; // Reset robot positions
        }
    }
    return -1;
}

int main() {
    int n, w, h, l;
    scanf("%d %d %d %d\n", &n, &w, &h, &l);
    vector<vector<char>> grid(h, vector<char>(w));
    vector<pair<pii, int>> robots;
    int targetX, targetY;
    for (int i = 0; i < h; ++i) {
        char line[13];
        fgets(line, 13, stdin);
        for (int j = 0; j < w; ++j) {
            if (line[j] == 'X') {
                targetY = i;
                targetX = j;
            }
            if (line[j] >= '0' && line[j] <= '9') {
                if (line[j] == '1') {
                    robots.push_back({{j, i}, 1});
                } else {
                    // Don't bother storing number for anything but robot 1
                    robots.push_back({{j, i}, 2});
                }
            }
            if (line[j] == 'W') {
                grid[i][j] = 'W';
            } else {
                // Don't store robot positions or target position in grid
                grid[i][j] = '.';
            }
        }
    }
    int r = solve(grid, robots, n, w, h, l, targetX, targetY);
    if (r >= 0) {
        printf("%d\n", r);
    } else {
        puts("NO SOLUTION");
    }
}
