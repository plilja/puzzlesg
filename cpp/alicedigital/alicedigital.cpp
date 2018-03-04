#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);
        int sum = 0,
            s1 = 0,
            s2 = 0,
            ans = 0;
        bool has_m = false;
        for (int j = 0; j < n; ++j) {
            int d;
            scanf("%d", &d);
            if (d < m) {
                sum = 0;
                s1 = 0;
                s2 = 0;
                has_m = false;
            }
            if (d >= m) {
                sum += d;
                s2 += d;
            }
            if (d == m) {
                sum -= s1;
                s1 = s2;
                s2 = 0;
                has_m = true;
            }
            if (has_m) {
                ans = max(ans, sum);
            }
        }
        printf("%d\n", ans);
    }
}
