#include <iostream>
#include <vector>
#include "combinatorics.h"

using namespace std;

typedef pair<int, int> pii;

bool in_line(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) == 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        char s[103];
        scanf("%s", s);
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }
    vector<pii> points;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            if (grid[y][x] != '.') {
                points.push_back({x, y});
            }
        }
    }
    int r = 0;
    for (auto p : waysToPick(points, 3)) {
        if (in_line(p[0].first, p[0].second, p[1].first, p[1].second, p[2].first, p[2].second)) {
            r++;
        }
    }
    printf("%d\n", r);
}
