#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> seq(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &seq[0][i]);
    }
    int order = 1;
    for (; order <= n; ++order) {
        bool all_same = true;
        for (int i = 0; i < n - order; ++i) {
            seq[order][i] = seq[order - 1][i + 1] - seq[order - 1][i];
            if (i > 0 && all_same) {
                all_same = seq[order][i - 1] == seq[order][i];
            }
        }
        if (all_same) {
            break;
        }
    }
    seq[order][n - order] = seq[order][n - order - 1]; 
    for (int i = order - 1; i >= 0; --i) {
       seq[i][n - i] = seq[i][n - i - 1] + seq[i + 1][n - i - 1];
    }
    printf("%d %d\n", order, seq[0][n]);
}
