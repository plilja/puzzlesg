#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        char s[55];
        scanf("%s", s);
        for (int j = 0; j < c; ++j) {
            grid[i][j] = s[j];
        }
    }
    vector<int> ans(5, 0);
    for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < c - 1; ++j) {
            int cars = 0;
            bool building = false;
            for (int h = 0; h < 2; ++h) {
                for (int k = 0; k < 2; ++k) {
                    char c = grid[i + h][j + k];
                    if (c == 'X') {
                        cars++;
                    } else if (c == '#') {
                        building = true;
                    }
                }
            }
            if (!building) {
                ans[cars]++;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", ans[i]);
    }
}
