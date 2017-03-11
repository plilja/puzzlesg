#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int C, P, X, L;
    scanf("%d %d %d %d", &C, &P, &X, &L);
    vector<vector<int>> graph(C + 1);
    for (int i = 0; i < P; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> remaining_partners(C + 1, 0);
    for (int i = 1; i <= C; ++i) {
        remaining_partners[i] = graph[i].size();
    }
    queue<int> q;
    q.push(L);
    vector<bool> leaving(C + 1, false);
    leaving[L] = true;
    while (!q.empty() && !leaving[X]) {
        int t = q.front();
        q.pop();
        for (int partner : graph[t]) {
            remaining_partners[partner]--;
            if (!leaving[partner] && remaining_partners[partner] <= graph[partner].size() / 2) {
                leaving[partner] = true;
                q.push(partner);
            }
        }
    }
    if (leaving[X]) {
        puts("leave");
    } else {
        puts("stay");
    }
}

