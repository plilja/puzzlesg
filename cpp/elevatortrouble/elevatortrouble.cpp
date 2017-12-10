#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    vector<int> v(f + 1, -1);
    queue<pair<int, int>> q;
    q.push({s, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int floor = p.first;
        int dist = p.second;
        if (v[floor] != -1) {
            continue;
        }
        v[floor] = dist;
        if (floor - d >= 1) {
            q.push({floor - d, dist + 1});
        }
        if (floor + u <= f) {
            q.push({floor + u, dist + 1});
        }
    }
    if (v[g] != -1) {
        printf("%d\n", v[g]);
    } else {
        puts("use the stairs");
    }
}
