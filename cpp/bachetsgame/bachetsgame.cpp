#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while (2 == scanf("%d %d", &n, &m)) {
        vector<int> v(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &v[i]);
        }
        vector<bool> wins(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (auto d : v) {
                if (i - d >= 0) {
                    if (!wins[i - d]) {
                        wins[i] = true;
                        break;
                    }
                }
            }
        }
        if (wins[n]) {
            puts("Stan wins");
        } else {
            puts("Ollie wins");
        }
    }
}