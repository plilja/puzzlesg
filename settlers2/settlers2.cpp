#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <limits>

using namespace std;

int main()
{
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        int n;
        scanf("%d", &n);
        int m = sqrt(n) + 1;
        vector<vector<int>> grid(2 * m + 1, vector<int>(2 * m + 1, 0));

        int counter = 1;
        int dirX = 0;
        int dirY = -1;
        int nextDirX = -1;
        int nextDirY = 0;
        vector<int> total_count(6, 0);
        int x = m;
        int y = m;
        grid[y][x] = 1;
        total_count[1] = 1;
        while (counter < n) {
            do {
                x += dirX;
                y += dirY;
                vector<int> neigh(6, 0);
                neigh[grid[y][x + 1]]++;
                neigh[grid[y][x - 1]]++;
                neigh[grid[y + 1][x]]++;
                neigh[grid[y - 1][x]]++;
                neigh[grid[y - 1][x - 1]]++;
                neigh[grid[y + 1][x + 1]]++;
                int g = numeric_limits<int>::max();
                int b = 0;

                for (int j = 5; j >= 1; --j) {
                    int k = neigh[j];
                    if (k == 0 && total_count[j] <= g) {
                        b = j;
                        g = total_count[j];
                    }
                }
                grid[y][x] = b;
                total_count[b]++;
                counter++;
            } while (grid[y + nextDirY][x + nextDirX] != 0 && counter < n);

            int tmpX, tmpY;
            if (nextDirX == 1 && nextDirY == 0) {
                tmpX = 0;
                tmpY = -1;
            } else if (nextDirX == 0 && nextDirY == -1) {
                tmpX = -1;
                tmpY = -1;
            } else if (nextDirX == -1 && nextDirY == -1) {
                tmpX = -1;
                tmpY = 0;
            } else if (nextDirX == -1 && nextDirY == 0) {
                tmpX = 0;
                tmpY = 1;
            } else if (nextDirX == 0 && nextDirY == 1) {
                tmpX = 1;
                tmpY = 1;
            } else {
                assert(nextDirX == 1 && nextDirY == 1);
                tmpX = 1;
                tmpY = 0;
            }
            dirX = nextDirX;
            dirY = nextDirY;
            nextDirX = tmpX;
            nextDirY = tmpY;
        }
        printf("%d\n", grid[y][x]);


    }
}
