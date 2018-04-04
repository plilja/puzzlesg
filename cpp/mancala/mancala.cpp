#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Precompute all solutions
    vector<vector<int>> bins(2001, vector<int>(81, 0));
    for (int i = 1; i <= 2000; ++i) {
        auto b = bins[i - 1];
        int free = 1;
        while (b[free] != 0) {
            b[free]--;
            free++;
        }
        b[free] = free;
        bins[i] = b;

    }

    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; ++i) {
        int k, n;
        scanf("%d %d", &k, &n);
        auto &ans = bins[n];
        int end = ans.size() - 1;
        while (ans[end] == 0) {
            --end;
        }
        printf("%d %d\n", k, end);
        for (int j = 1; j <= end; ++j) {
            printf("%d", ans[j]);
            if (j < end && j % 10 != 0) {
                printf(" ");
            }
            if (j == end || j % 10 == 0) {
                printf("\n");
            }
        }
    }
}
