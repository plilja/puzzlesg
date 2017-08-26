#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    printf("%d\n", t);
    for (int i = 0; i < t; ++i) {
        char str[20005];
        scanf("%s", str);
        int n = strlen(str);

        // Walk input and record maze
        vector<vector<char>> maze(201, vector<char>(100, '#'));
        int x = 0, y = 100,
            dx = 1, dy = 0,
            max_x = 0, min_y = y, max_y = y;
        maze[y][x] = '.';
        for (int j = 0; j < n; ++j) {
            char d = str[j];
            switch (d)
            {
                case 'R':
                    swap(dx, dy);
                    dx = -dx;
                    break;
                case 'F':
                    break;
                case 'L':
                    swap(dx, dy);
                    dy = -dy;
                    break;
                case 'B':
                    dx = -dx;
                    dy = -dy;
                    break;
            }
            x += dx;
            y += dy;
            maze[y][x] = '.';
            max_x = max(x, max_x);
            min_y = min(y, min_y);
            max_y = max(y, max_y);
        }

        // Print answer
        int h = max_y - min_y + 3;
        int w = max_x + 2;
        printf("%d %d\n", h, w);

        // Print top border
        for (int j = 0; j < w; ++j) {
            printf("%c", '#');
        }
        printf("\n");

        // Print deduced maze
        for (int k = min_y; k < max_y + 1; ++k) {
            for (int j = 0; j < max_x + 1; ++j) {
                printf("%c", maze[k][j]);
            }
            printf("#\n");
        }

        // Print bottom border
        for (int j = 0; j < w; ++j) {
            printf("%c", '#');
        }
        printf("\n");
    }
}
