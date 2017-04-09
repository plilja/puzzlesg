#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<bool>> allowed(n, vector<bool>(n, true));
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        allowed[a - 1][b - 1] = false;
        allowed[b - 1][a - 1] = false;
    }
    int ans = 0;
    int lim = 1 << n;
    for (int j = 0; j < lim; ++j) {
        bitset<20> bs(j);
        bool poss = true;
        for (int a = 0; a < n && poss; ++a) {
            for (int b = a + 1; bs[a] && b < n && poss; ++b) {
                poss = !bs[b] || allowed[a][b];
            }
        }
        if (poss) {
            ans++;
        }
    }
    printf("%d\n", ans);
}
