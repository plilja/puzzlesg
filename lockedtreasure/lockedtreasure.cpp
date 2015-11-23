#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> binom(31, vector<int>(31, 0));
    binom[0][0] = 1;
    for (int i = 1; i <= 30; ++i) {
        for (int j = 0; j <= 30; ++j) {
            if (j > 0) {
                binom[i][j] += binom[i - 1][j - 1];
            }
            if (j < i) {
                binom[i][j] += binom[i - 1][j];
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        int n, m;
        scanf("%d %d", &n, &m);
        int r = binom[n][m - 1];
        printf("%d\n", r);
    }
}
