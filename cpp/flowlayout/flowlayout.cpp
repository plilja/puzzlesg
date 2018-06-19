#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int m;
        scanf("%d", &m);
        if (m == 0) {
            break;
        }
        int w = 0,
            h = 0,
            row_w = 0,
            row_h = 0,
            window_w,
            window_h;
        while (true) {
            scanf("%d %d", &window_w, &window_h);
            if (-1 == window_h && -1 == window_h) {
                break;
            }
            if (row_w + window_w > m) {
                // need new row?
                w = max(w, row_w);
                h += row_h;
                row_w = 0;
                row_h = 0;
            }
            row_w += window_w;
            row_h = max(row_h, window_h);
        }
        w = max(w, row_w);
        h += row_h;
        printf("%d x %d\n", w, h);
    }
}
