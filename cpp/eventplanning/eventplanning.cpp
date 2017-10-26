#include <iostream>
#include <algorithm>

using namespace std;

int INF = 10000 * 200 + 1;

int main()
{
    int n, b, h, w;
    scanf("%d %d %d %d", &n, &b, &h, &w);
    int best = INF;
    for (int i = 0; i < h; ++i) {
        int p;
        scanf("%d", &p);
        for (int j = 0; j < w; ++j) {
            int a;
            scanf("%d", &a);
            if (a >= n) {
                best = min(best, n * p);
            }
        }
    }
    if (best < INF && best < b) {
        printf("%d\n", best);
    } else {
        printf("stay home\n");
    }
}
