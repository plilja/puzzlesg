#include <iostream>
#include <vector>

using namespace std;

int main()
{
    while (true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        vector<pair<int, int>> calls(n);
        for (int i = 0; i < n; ++i) {
            int dummy1, dummy2, a, b;
            scanf("%d %d %d %d", &dummy1, &dummy2, &a, &b);
            calls[i] = {a, a + b};
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            b = a + b;
            int r = 0;
            for (auto &call : calls) {
                if (call.first < b && call.second > a) {
                    ++r;
                }
            }
            printf("%d\n", r);
        }
    }
}
