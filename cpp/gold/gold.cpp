#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

pii DELTAS[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};

int main()
{
    // Read input
    int w, h;
    scanf("%d %d", &w, &h);
    vector<vector<char>> grid(h, vector<char>(w));
    for (int y = 0; y < h; ++y) {
        char s[60];
        scanf("%s", s);
        for (int x = 0; x < w; ++x) {
            grid[y][x] = s[x];
        }
    }

    // Find starting position
    int startX, startY;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (grid[y][x] == 'P') {
                startX = x;
                startY = y;
            }
        }
    }

    // Breadth first search
    int ans = 0;
    queue<pii> q;
    q.push({startX, startY});
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (visited[y][x]) {
            continue;
        }
        visited[y][x] = true;
        if (grid[y][x] == 'G') {
            ans++;
        }
        bool draft = false;
        for (auto d : DELTAS) {
            if (grid[y + d.second][x + d.first] == 'T') {
                draft = true;
            }
        }
        if (draft) {
            continue;
        }
        for (auto d : DELTAS) {
            if (grid[y + d.second][x + d.first] != '#') {
                q.push({x + d.first, y + d.second});
            }
        }
    }

    printf("%d\n", ans);
}
