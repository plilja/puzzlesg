#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;

int solve(vvc &m, int r, int c)
{
    vvi up(r + 1, vector<int>(c + 1, 0));
    vvi down(r + 1, vector<int>(c + 1, 0));
    vvi right(r + 1, vector<int>(c + 1, 0));

    up[1][c - 1] = 1;
    for (int i = c - 1; i >= 0; --i) {
        for (int j = 1; j <= r; ++j) {
            if (m[j - 1][i] == '#') {
                up[j][i] = 0;
                down[j][i] = 0;
                right[j][i] = 0;
            }
        }
        for (int j = 1; j <= r; ++j) {
            if (m[j - 1][i] == '.') {
                right[j][i] = up[j][i + 1] + down[j][i + 1] + right[j][i + 1];
            }
        }
        for (int j = 2; j <= r; ++j) {
            if (m[j - 1][i] == '.') {
                up[j][i] = up[j - 1][i] + right[j - 1][i];
            }
        }
        for (int j = r - 1; j >= 1; --j) {
            if (m[j - 1][i] == '.') {
                down[j][i] = down[j + 1][i] + right[j + 1][i];
            }
        }
    }

    return up[r][0] + right[r][0];
}

int main()
{
    while (true) {
        int r, c;
        scanf("%d %d\n", &r, &c);
        if (r == 0 && c == 0)
            break;
        vvc m(r, vector<char>(c));
        for (int i = 0; i < r; ++i) {
            char line[12];
            fgets(line, 12, stdin);
            for (int j = 0; j < c; ++j) {
                m[i][j] = line[j];
            }
        }
        int a = solve(m, r, c);
        printf("%d\n", a);
    }
}
