#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d\n", &m, &n);
    vector<vector<bool>> grid(m, vector<bool>(n, true));
    int blacks = 0;
    for (int i = 0; i < m; ++i) {
        char line[102];
        fgets(line, 102, stdin);
        for (int j = 0; j < n; ++j) {
            char c = line[j];
            if (c == 'X') {
                blacks++;
                grid[i][j] = false;
            }
        }
    }
    bool possible;
    if (m * n < 4) {
        possible = blacks == 0;
    } else if (m * n == 4) {
        possible = blacks % 4 == 0;
    } else if (m == 1 || n == 1) {
        int dy = m == 1 ? 0 : 1;
        int dx = n == 1 ? 0 : 1;
        possible = true;
        for (int i = 0, j = 0; i < m && j < n; i += dy, j += dx) {
            if (!grid[i][j] && i + 3 * dy < m && j + 3 * dx < n) {
                for (int h = 0; h < 4; ++h) {
                    grid[i + h * dy][j + h * dx] = !grid[i + h * dy][j + h * dx];
                }
            }
            possible = possible && grid[i][j];
        }
    } else {
        possible = blacks % 2 == 0;
    }

    if (possible) {
        puts("possible");
    } else {
        puts("impossible");
    }
}
