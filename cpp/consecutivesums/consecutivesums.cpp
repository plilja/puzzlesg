#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        pair<int, int> ans = {-1, -1};
        for (int len = 2; len*len <= 2*n; ++len) {
            // n = a + (a + 1) + ... + (a + len - 1) = 
            // a*len + (len - 1)*len/2 = len * (2*a + len - 1) / 2
            // <=> 2 * n == len * (2 * a + len - 1)
            if (2*n % len != 0) {
                continue;
            }
            int tmp = 2 * n / len + 1 - len;
            if (tmp % 2 != 0) {
                continue;
            }
            int a = tmp / 2;
            ans = {a, a + len - 1};
            break;
        }
        if (ans.first == -1) {
            puts("IMPOSSIBLE");
        } else {
            printf("%d = ", n);
            for (int i = ans.first; i < ans.second; ++i) {
                printf("%d + ", i);
            }
            printf("%d\n", ans.second);
        }
    }
}
