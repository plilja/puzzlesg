#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

pii find_start(int x, int y, vector<vector<char>> &grid) {
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (grid[i][j] == 'S') {
                return {j, i};
            }
        }
    }
    return {-1, -1};
}

vector<pair<pii, int>> bfs(int x, int y, vector<vector<char>> &grid, pii from) {
    vector<pair<pii, int>> r;
    queue<pair<pii, int>> q;
    q.push({from, 0});
    vector<vector<bool>> visited(y, vector<bool>(x, false));
    visited[from.second][from.first] = true;
    while (!q.empty()) {
        auto t = q.front();
        auto coord = t.first;
        if (grid[coord.second][coord.first] == 'A') {
            r.push_back(t);
        }
        q.pop();
        pii deltas[4] = {{0,  1},
                         {0,  -1},
                         {1,  0},
                         {-1, 0}};
        for (auto delta : deltas) {
            if (grid[coord.second + delta.second][coord.first + delta.first] != '#' &&
                !visited[coord.second + delta.second][coord.first + delta.first]) {
                visited[coord.second + delta.second][coord.first + delta.first] = true;
                q.push({{coord.first + delta.first, coord.second + delta.second}, t.second + 1});
            }
        }
    }
    return r;
}

int solve(int x, int y, vector<vector<char>> &grid) {
    pii s = find_start(x, y, grid);
    priority_queue<pair<int, pii>> q;
    q.push({0, s});
    int ans = 0;
    vector<vector<bool>> visited(y, vector<bool>(x, false));
    while (!q.empty()) {
        auto t = q.top();
        auto coord = t.second;
        q.pop();
        if (visited[coord.second][coord.first]) {
            continue;
        }
        visited[coord.second][coord.first] = true;
        ans += (-t.first);
        for (auto tmp : bfs(x, y, grid, t.second)) {
            auto neighbour = tmp.first;
            int dist = tmp.second;
            if (!visited[neighbour.second][neighbour.first]) {
                q.push({-dist, neighbour});
            }
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        vector<vector<char>> grid(y, vector<char>(x));
        for (int i = 0; i < y; ++i) {
            char line[52];
            fgets(line, 52, stdin);
            for (int j = 0; j < x; ++j) {
                grid[i][j] = line[j];
            }
        }
        int r = solve(x, y, grid);
        printf("%d\n", r);
    }
}
