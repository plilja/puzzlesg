#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, r, s;
    scanf("%d %d %d", &k, &r, &s);
    vector<vector<int>> window(k, vector<int>(r));
    vector<vector<int>> flies(k, vector<int>(r));

    // Read input grid
    for (int y = 0; y < k; ++y) {
        char s[105];
        scanf("%s", s);
        int f = 0;
        for (int x = 0; x < r; ++x) {
            if (s[x] == '*') {
                f++;
            }
            flies[y][x] = f;
            window[y][x] = s[x];
        }
    }

    // Determine top left corner of racket
    int best = 0, 
        best_x = 0, 
        best_y = 0;
    for (int y = 0; y <= k - s; ++y) {
        for (int x = 0; x <= r - s; ++x) {
            int kills = 0;
            for (int i = 1; i < s - 1; ++i) {
                kills += flies[y + i][x + s - 2] - flies[y + i][x];
            }
            if (kills > best) {
                best = kills;
                best_x = x;
                best_y = y;
            }
        }
    }

    // Draw racket onto window
    for (int i = 0; i < s; ++i) {
        if (i == 0 || i == s - 1) {
            window[best_y + i][best_x] = '+';
            window[best_y][best_x + i] = '+';
            window[best_y + s - 1][best_x + i] = '+';
            window[best_y + i][best_x + s - 1] = '+';
        } else {
            window[best_y + i][best_x] = '|';
            window[best_y][best_x + i] = '-';
            window[best_y + s - 1][best_x + i] = '-';
            window[best_y + i][best_x + s - 1] = '|';
        }
    }
    
    // Output answer
    printf("%d\n", best);
    for (int y = 0; y < k; ++y) {
        for (int x = 0; x < r; ++x) {
            printf("%c", window[y][x]);
        }
        printf("\n");
    }
}
