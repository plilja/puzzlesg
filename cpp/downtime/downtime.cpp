#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> requests(101001, 0);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < 1000; ++j) {
            requests[t + j] += 1;
        }
    }
    int m = -1;
    for (int r : requests) {
        m = max(m, r);
    }
    int ans = (m + k - 1) / k;
    printf("%d\n", ans);
}
