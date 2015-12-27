#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int bit(int num, int bit)
{
    return (num & (1 << bit)) >> bit;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<vector<int>> m(n, vector<int>(k));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                scanf("%d", &m[i][j]);
            }
        }
        int max_n = (1 << k) - 1;
        int r = n;
        for (int i = 1; i <= max_n; ++i) {
            int d = 0;
            for (int j = 0; j < n; ++j) {
                int s = 0;
                for (int h = 0; h < k; ++h) {
                    s += m[j][h] * bit(i, h);
                }
                d += (s % 2);
            }
            r = min(r, d);
        }
        printf("%d\n", r);

    }
}
