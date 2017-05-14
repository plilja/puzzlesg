#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, g;
        scanf("%d %d", &n, &g);
        g--; // make zero indexed
        vector<vector<int>> city(n, vector<int>(4));
        for (int j = 0; j < n; ++j) {
            vector<int> &i = city[j];
            scanf("%d %d %d %d", &i[0], &i[1], &i[2], &i[3]);
            for (int k = 0; k < 4; ++k) {
                i[k]--; // make zero indexed
            }
        }
        int ans = 0;
        queue<pii> q1;
        q1.push({g, 0});
        q1.push({g, 1});
        vector<vector<bool>> visited(n, vector<bool>(4, false));
        while (!q1.empty()) {
            auto p1 = q1.front();
            q1.pop();
            if (visited[p1.first][p1.second]) {
                continue;
            }
            if (p1.first != g) {
                ans++;
            }
            queue<pii> q2;
            q2.push(p1);
            while (!q2.empty()) {
                auto p2 = q2.front();
                q2.pop();
                if (visited[p2.first][p2.second]) {
                    continue;
                }
                visited[p2.first][p2.second] = true;
                visited[p2.first][(p2.second + 2) % 4] = true;
                int intersection = p2.first;
                int next_intersection = city[intersection][(p2.second + 2) % 4];
                int next_position;
                for (int j = 0; j < 4; ++j) {
                    if (city[next_intersection][j] == intersection) {
                        next_position = j;
                    }
                }
                q1.push({next_intersection, (next_position + 1) % 4});
                q2.push({next_intersection, next_position});
            }
        }
        printf("%d\n", ans);
    }
}
