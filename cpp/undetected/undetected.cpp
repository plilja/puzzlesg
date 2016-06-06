#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const double EPS = 1e-10;

struct Sensor {
    int x, y, r;
    bool touchesLeft, touchesRight;
};

int main() {
    int n;
    scanf("%d", &n);
    vector<Sensor> sensors(n);
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        bool touchesLeft = (x <= r);
        bool touchesRight = (200 - x <= r);
        sensors[i] = Sensor({x, y, r, touchesLeft, touchesRight});
    }
    vector<vector<int>> g(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto &s = sensors[i];

        for (int j = 0; j < i; ++j) {
            auto &s2 = sensors[j];
            if (sqrt(pow(s.x - s2.x, 2) + pow(s.y - s2.y, 2)) < s.r + s2.r + EPS) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        queue<int> q;
        for (int j = 0; j <= i; ++j) {
            if (sensors[j].touchesLeft) {
                q.push(j);
            }
        }
        bool poss = true;
        vector<int> v(n, false);
        while (!q.empty()) {
            auto k = q.front();
            q.pop();
            if (v[k]) {
                continue;
            }
            v[k] = true;
            if (sensors[k].touchesRight) {
                poss = false;
                break;
            }
            for (int b : g[k]) {
                q.push(b);
            }
        }
        if (!poss) {
            break;
        } else {
            ans = i + 1;
        }
    }
    printf("%d\n", ans);

}

