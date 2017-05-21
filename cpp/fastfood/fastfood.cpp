#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<int>> prices(n);
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                int sticker;
                scanf("%d", &sticker);
                prices[i].push_back(sticker - 1);
            }
            int value;
            scanf("%d", &value);
            values[i] = value;
        }
        vector<int> stickers(m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &stickers[j]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int nr = stickers[prices[i][0]];
            for (int j = 0; j < prices[i].size(); ++j) {
                nr = min(nr, stickers[prices[i][j]]);
            }
            ans += nr * values[i];
        }
        printf("%d\n", ans);
    }
}
