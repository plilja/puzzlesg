#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void move(vector<vi> &g, int d, int start, int step, vector<vi> stopped)
{
    for (int reps = 0; reps < 4; ++reps) {
        for (int i = 0; i < 4; ++i) {
            for (int j = start; j >= 0 && j <= 3; j -= step) {
                int *prev;
                int *curr;
                int *s1;
                int *s2;
                if (d == 0 || d == 2) {
                    // left or right
                    prev = &g[i][j + step];
                    curr = &g[i][j];
                    s1 = &stopped[i][j];
                    s2 = &stopped[i][j + step];
                } else {
                    // up or down
                    prev = &g[j + step][i];
                    curr = &g[j][i];
                    s1 = &stopped[j][i];
                    s2 = &stopped[j + step][i];
                }

                if (*curr == 0 || *s1 == 1 || *s2 == 1) {
                    continue;
                }
                if (*prev == 0) {
                    *prev = *curr;
                    *curr = 0;
                } else if (*prev == *curr) {
                    *prev *= 2;
                    *curr = 0;
                    *s2 = 1;
                }
            }
        }
     }
}

int main()
{
    vector<vi> g(4, vi(4));
    vector<vi> stopped(4, vi(4, 0));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    int d;
    scanf("%d", &d);
    if (d <= 1) {
        move(g, d, 1, -1, stopped);
    } else {
        move(g, d, 2, 1, stopped);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d", g[i][j]);
            if (j != 3)
                printf(" ");
        }
        puts("");
    }
}
