#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> rotate(vector<vector<char>> &grid) {
    auto n = grid.size();
    vector<vector<char>> new_grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            new_grid[j][n - i - 1] = grid[i][j];
        }
    }
    return new_grid;
}

bool is_fully_decrypted(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '?') {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        char s[13];
        scanf("%s", s);
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }
    char enc[103], dec[103];
    for (int i = 0; i < 100; ++i) {
        dec[i] = '?';
    }
    dec[n*n] = '\0';
    scanf("%s", enc);
    int k = 0;
    bool valid = true;
    for (int rot = 0; rot < 4; ++rot) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (valid && grid[i][j] == '.') {
                    valid = valid && dec[n*i + j] == '?';
                    if (valid) {
                        dec[n*i + j] = enc[k];
                        k++;
                    }
                }
            }
        }
        grid = rotate(grid);
    }

    if (valid && is_fully_decrypted(dec)) {
        puts(dec);
    } else {
        puts("invalid grille");
    }
}
