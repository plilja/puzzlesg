#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int j = 0; j < m; ++j) {
        v[0][j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        v[i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int prev_swather = v[i - 1][j];
            int prev_stage = v[i][j - 1];
            int c;
            scanf("%d", &c);
            int stage_done = max(prev_swather, prev_stage) + c;
            v[i][j] = stage_done;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", v[i][m]);
    }
    printf("\n");
}
