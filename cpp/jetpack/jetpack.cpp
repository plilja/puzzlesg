#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<char>> field(10, vector<char>(n));
    for (int y = 0; y < 10; ++y) {
        char s[100003];
        scanf("%s", s);
        for (int x = 0; x < n; ++x) {
            field[9 - y][x] = s[x]; 
        }
    }
    queue<pii> q;
    vector<vector<int>> pre(10, vector<int>(n));
    vector<vector<int>> press(10, vector<int>(n, 0));
    vector<vector<bool>> visited(10, vector<bool>(n, false));
    q.push({0, 0});
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        if (visited[y][x]) {
            continue;
        }
        visited[y][x] = true;
        if (x == n - 1) {
            continue;
        }
        int p = press[y][x];
        if (y > 0 && field[y - 1][x + 1] == '.') {
            pre[y - 1][x + 1] = y;
            press[y - 1][x + 1] = 0;
            q.push({x + 1, y - 1});
        }
        if ((y == 0 || y == 9) && field[y][x + 1] == '.') {
            pre[y][x + 1] = y;
            q.push({x + 1, y});
            if (y == 9) {
                press[y][x + 1] = p + 1;
            } else {
                press[y][x + 1] = 0;
            }
        }
        if (y < 9 && field[y + 1][x + 1] == '.') {
            pre[y + 1][x + 1] = y;
            q.push({x + 1, y + 1});
            press[y + 1][x + 1] = p + 1;
        }
    }
    int end_y = -1;
    for (int y = 0; y < 10; ++y) {
        if (visited[y][n - 1]) {
            end_y = y;
            break;
        }
    }
    assert(end_y != -1);
    vector<pii> ans;
    int x = n - 1,
        y = end_y,
        p = press[y][x];
    while (x >= 0) {
        int next_p = press[y][x];
        if (next_p == 0 && p > 0) {
            ans.push_back({x, p});
            p = 0;
        }
        if (next_p > 0 && p == 0) {
            p = next_p;
        }
        y = pre[y][x];
        x--;
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (pii p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
}
