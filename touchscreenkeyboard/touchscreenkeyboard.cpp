#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int INF = 1000;

string keyboard[] = {"qwertyuiop",
                     "asdfghjkl",
                     "zxcvbnm"
                    };

vector<vector<int>> char_dists(26, vector<int>(26, 0));

pair<int, int> indexOf(char c)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < (int)keyboard[i].size(); ++j) {
            if (keyboard[i][j] == c)
                return {j, i};
        }
    }
    throw - 1;
}

int charDist(char a, char b)
{
    queue<pair<int, int>> q;
    q.push(indexOf(a));
    vector<int> d(26, INF);
    d[a - 'a'] = 0;
    while (d[b - 'a'] == INF && !q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        char c = keyboard[y][x];
        int dist = d[c - 'a'];
        if (x > 0) {
            q.push({x - 1, y});
            d[keyboard[y][x - 1] - 'a'] = dist + 1;
        }
        if (y > 0) {
            q.push({x, y - 1});
            d[keyboard[y - 1][x] - 'a'] = dist + 1;
        }
        if (x + 1 < (int)keyboard[y].size()) {
            q.push({x + 1, y});
            d[keyboard[y][x + 1] - 'a'] = dist + 1;
        }
        if (y + 1 < 3 && x < (int)keyboard[y + 1].size()) {
            q.push({x, y + 1});
            d[keyboard[y + 1][x] - 'a'] = dist + 1;
        }
    }
    return d[b - 'a'];
}

void initCharDists()
{
    for (char i = 'a'; i <= 'z'; ++i) {
        for (int j = i; j <= 'z'; ++j) {
            int d = charDist(i, j);
            char_dists[i - 'a'][j - 'a'] = d;
            char_dists[j - 'a'][i - 'a'] = d;
        }
    }
}

int dist(string &a, string &b)
{
    int r = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        r += char_dists[a[i] - 'a'][b[i] - 'a'];
    }
    return r;
}

int main()
{
    initCharDists();
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        string typed;
        int dict_size;
        cin >> typed >> dict_size;
        vector<pair<int, string>> dict;
        for (int i = 0; i < dict_size; ++i) {
            string w;
            cin >> w;
            int d = dist(w, typed);
            dict.push_back({d, w});
        }
        sort(dict.begin(), dict.end());
        for (auto p : dict) {
            cout << p.second << " " << p.first << endl;
        }
    }
}

