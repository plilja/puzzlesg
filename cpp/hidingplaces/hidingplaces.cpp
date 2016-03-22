#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

const int INF = 1000;

string pos_to_str(int x, int y) {
    stringstream s;
    s << (char) (x + (int) 'a') << (y + 1);
    return s.str();
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int x = (int) (s[0] - 'a');
        int y = (int) (s[1] - '1');
        vector<vector<int>> v(8, vector<int>(8, INF));
        queue<pair<pair<int, int>, int>> q;
        q.push({{x, y}, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            x = t.first.first;
            y = t.first.second;
            int d = t.second;
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                continue;
            }
            if (v[x][y] < INF) {
                continue;
            }
            v[x][y] = d;
            q.push({{x + 1, y + 2}, d + 1});
            q.push({{x - 1, y + 2}, d + 1});
            q.push({{x + 1, y - 2}, d + 1});
            q.push({{x - 1, y - 2}, d + 1});
            q.push({{x + 2, y + 1}, d + 1});
            q.push({{x - 2, y + 1}, d + 1});
            q.push({{x + 2, y - 1}, d + 1});
            q.push({{x - 2, y - 1}, d + 1});
        }
        int best = 0;
        vector<string> answers;
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                int d = v[j][i];
                if (d > best) {
                    best = d;
                    answers.clear();
                }
                if (d == best) {
                    answers.push_back(pos_to_str(j, i));
                }
            }
        }
        cout << best;
        for (auto &a : answers) {
            cout << " " << a;
        }
        cout << endl;
    }
}
