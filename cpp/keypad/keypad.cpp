#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int r, c;
        scanf("%d %d\n", &r, &c);
        vector<vector<bool>> grid(r, vector<bool>(c));
        for (int i = 0; i < r; ++i) {
            char s[13];
            fgets(s, 13, stdin);
            for (int j = 0; j < c; ++j) {
                grid[i][j] = s[j] == '0' ? false : true;
            }
        }
        vector<int> rows(r, 0);
        vector<int> cols(c, 0);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        bool possible = true;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (rows[i] > 0 && cols[j] > 0 && !grid[i][j]) {
                    possible = false;
                }
            }
        }
        if (!possible) {
            puts("impossible");
            puts("----------");
            continue;
        }
        vector<vector<char>> ans(r, vector<char>(c, 'N'));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    if (rows[i] == 1 || cols[j] == 1) {
                        ans[i][j] = 'P';
                    } else {
                        ans[i][j] = 'I';
                    }
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                printf("%c", ans[i][j]);
            }
            puts("");
        }
        puts("----------");
    }
}
