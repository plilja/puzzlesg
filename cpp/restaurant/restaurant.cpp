#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

int main()
{
    while (true) {
        int n;
        scanf("%d\n", &n);
        if (n == 0)
            break;

        int pile1 = 0, pile2 = 0;
        for (int i = 0; i < n; ++i) {
            char s[5];
            int m;
            scanf("%s %d\n", s, &m);

            if (strncmp(s,  "DROP", 4) == 0) {
                pile1 += m;
                printf("DROP 1 %d\n", m);
            } else {
                assert(strncmp(s, "TAKE", 4) == 0);
                int from_pile2 = min(pile2, m);
                m -= from_pile2;
                pile2 -= from_pile2;
                if (from_pile2 > 0) {
                    printf("TAKE 2 %d\n", from_pile2);
                }
                if (m > 0) {
                    printf("MOVE 1->2 %d\n", pile1);
                    printf("TAKE 2 %d\n", m);
                    pile2 = pile1 - m;
                    pile1 = 0;

                }
            }
        }
        puts("");
    }
}
