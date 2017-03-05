#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int t = 1;
    while (true) {
        int w, n;
        scanf("%d %d", &w, &n);
        if (w ==  0 && n == 0) {
            break;
        }
        vector<pair<int, int>> words;
        int maxC = -1;
        for (int i = 0; i < n; ++i) {
            char s[10000];
            int c;
            scanf("%s %d", s, &c); 
            maxC = max(maxC, c);
            int len = strlen(s);
            words.push_back({len, c});
        }
        int ans = 0;
        int leftInRow = w;
        int rowHeight = 0;
        for (auto &wordAndCount : words) {
            int p = 8 + ceil(40.0 * (wordAndCount.second - 4.0) / (maxC - 4.0));
            int wordWidth = ceil((9.0/16.0) * p * wordAndCount.first);
            if (wordWidth > leftInRow) {
                ans += rowHeight;
                leftInRow = w;
                rowHeight = 0;
            }
            leftInRow -= wordWidth;
            leftInRow -= 10; // spacing
            rowHeight = max(rowHeight, p);
        }
        ans += rowHeight;
        printf("CLOUD %d: %d\n", t, ans);
        t++;
    }
}
