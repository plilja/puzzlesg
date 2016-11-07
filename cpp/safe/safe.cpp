#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pressButton(vector<vector<int>> &v, int y, int x) {
    for (int k = 0; k < 3; ++k) {
        v[y][k] = (v[y][k] + 1) % 4;
        if (k != y) {
            v[k][x] = (v[k][x] + 1) % 4;
        }
    }
}

int solve(vector<vector<int>> &v, int y, int x) {
    bool done = true;
    for (int i = 0; i < 3 && done; ++i) {
        for (int j = 0; j < 3 && done; ++j) {
            done = done && v[i][j] == 0;
        }
    }
    if (done) {
        return 0;
    } else if (x == 3) {
        return solve(v, y + 1, 0);
    } else if (y == 3) {
        return -1;
    } else {
        int r = -1;
        for (int i = 0; i <= 3; ++i) {
            int sub = solve(v, y, x + 1);
            if (sub != -1) {
                if (r != -1) {
                    r = min(r, sub + i);
                } else {
                    r = sub + i;
                }
            }
            pressButton(v, y, x);
        }
        return r;
    }
}

int main() {
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    int r = solve(v, 0, 0);
    printf("%d\n", r);
}
