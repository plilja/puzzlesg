#include <iostream>
#include <vector>

using namespace std;

int beats(char c1, char c2) {
    if (c1 == 'R' && c2 == 'S') {
        return 1;
    } else if (c1 == 'S' && c2 == 'P') {
        return 1;
    } else if (c1 == 'P' && c2 == 'R') {
        return 1;
    } else if (c1 == c2) {
        return 0;
    } else {
        return -1;
    }
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int r, c, n;
        scanf("%d %d %d\n", &r, &c, &n);
        vector<vector<vector<char>>> grid(2, vector<vector<char>>(r, vector<char>(c)));
        for (int i = 0; i < r; ++i) {
            char s[105];
            fgets(s, 105, stdin);
            for (int j = 0; j < c; ++j) {
                grid[0][i][j] = s[j];
            }
        }
        for (int round = 1; round <= n; ++round) {
            auto &pre_gr = grid[(round - 1) % 2];
            auto &next_gr = grid[round % 2];
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    next_gr[i][j] = pre_gr[i][j];
                }
            }
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (i < r - 1) {
                        int r = beats(pre_gr[i][j], pre_gr[i + 1][j]);
                        if (r > 0) {
                            next_gr[i + 1][j] = pre_gr[i][j];
                        } else if (r < 0) {
                            next_gr[i][j] = pre_gr[i + 1][j];
                        }
                    }
                    if (j < c - 1) {
                        int r = beats(pre_gr[i][j], pre_gr[i][j + 1]);
                        if (r > 0) {
                            next_gr[i][j + 1] = pre_gr[i][j];
                        } else if (r < 0) {
                            next_gr[i][j] = pre_gr[i][j + 1];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                printf("%c", grid[n % 2][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
