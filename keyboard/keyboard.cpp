#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

typedef pair<int, int> pii;

const int INF = 2501 * 10001;

void calcDists(vector<vector<char>> &keyboard, vector<vector<vector<vector<pair<pii, int>>>>> &dists, pii a, char target)
{
    queue<pii> q;
    q.push(a);
    vector<vector<int>> d(50, vector<int>(50, INF));
    vector<vector<bool>> v(50, vector<bool>(50, false));
    d[a.second][a.first] = 0;
    v[a.second][a.first] = true;
    vector<pii> pos;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        char c = keyboard[y][x];

        bool target_found = (c == target);
        int dist = dist;
        if (target_found) {
            dist = INF;
            pos.push_back(p);
        } else {
            dist = d[y][x];
        }

        int xp = x - 1;
        while (xp >= 0 && keyboard[y][xp] == c) {
            --xp;
        }
        if (xp >= 0 && (!v[y][xp] || (target_found && d[y][xp] >= d[y][x] + 1))) {
            if (dist < INF)
                q.push({xp, y});
            d[y][xp] = dist + 1;
            v[y][xp] = true;
        }
        xp = x + 1;
        while (xp < (int)keyboard[y].size() && keyboard[y][xp] == c) {
            ++xp;
        }
        if (xp < (int)keyboard[y].size() && (!v[y][xp] || (target_found && d[y][xp] >= d[y][x] + 1))) {
            if (dist < INF)
                q.push({xp, y});
            d[y][xp] = dist + 1;
            v[y][xp] = true;
        }
        int yp = y - 1;
        while (yp >= 0 && keyboard[yp][x] == c) {
            --yp;
        }
        if (yp >= 0 && (!v[yp][x] || (target_found && d[yp][x] >= d[y][x] + 1))) {
            if (dist < INF)
                q.push({x, yp});
            d[yp][x] = dist + 1;
            v[yp][x] = true;
        }
        yp = y + 1;
        while (yp < (int)keyboard.size() && keyboard[yp][x] == c) {
            ++yp;
        }
        if (yp < (int)keyboard.size() && (!v[yp][x] || (target_found && d[yp][x] >= d[y][x] + 1))) {
            if (dist < INF)
                q.push({x, yp});
            d[yp][x] = dist + 1;
            v[yp][x] = true;
        }
    }
    for (auto &p : pos) {
        int x = p.first;
        int y = p.second;
        if (d[y][x] < INF) {
            dists[a.second][a.first][(int)(target)].push_back({p, d[y][x]});;
        }
    }
}


int keyPresses(vector<vector<char>> &keyboard, int r, int c, string &text)
{
    text.append("*"); //need to finish with enter
    vector<vector<vector<vector<pair<pii, int>>>>> dists(50, vector<vector<vector<pair<pii, int>>>>(50, vector<vector<pair<pii, int>>>(100, vector<pair<pii, int>>())));
    vector<vector<vector<int>>> M(2, vector<vector<int>>(r, vector<int>(c, INF)));
    M[0][0][0] = 0;


    for (int i = 1; i <= (int)text.size(); ++i) {
        for (int y = 0; y < r; ++y) {
            for (int x = 0; x < c; ++x) {
                M[i % 2][y][x] = INF;
            }
        }

        char ch = text[i - 1];
        for (int y = 0; y < r; ++y) {
            for (int x = 0; x < c; ++x) {
                if (M[(i - 1) % 2][y][x] < INF) {
                    int m = M[(i - 1) % 2][y][x];
                    if (dists[y][x][(int) ch].empty()) {
                        calcDists(keyboard, dists, {x, y}, ch);
                    }
                    for (auto &it : dists[y][x][(int)ch]) {
                        auto &p = it.first;
                        int cd = it.second;
                        int dist = m + cd + 1;
                        M[i % 2][p.second][p.first] = min(M[i % 2][p.second][p.first], dist);
                    }
                }
            }
        }
    }
    int ans = INF;
    char last_char = text[text.size() - 1];
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            if (keyboard[y][x] == last_char) {
                ans = min(ans, M[text.size() % 2][y][x]);
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int r, c;
    scanf("%d %d\n", &r, &c);
    vector<vector<char>> keyboard(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        char row[52];
        fgets(row, 52, stdin);
        for (int j = 0; j < c; ++j) {
            keyboard[i][j] = row[j];
        }
    }
    char _text[10002];
    scanf("%s", _text);
    string text(_text);
    int ans = keyPresses(keyboard, r, c, text);
    printf("%d\n", ans);
}

