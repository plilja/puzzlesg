#include "disjoint_set.h"
#include <iostream>

using namespace std;

int main()
{
    int n, q;
    scanf("%d %d\n", &n, &q);
    DisjointSet ds(n);
    for (int i = 0; i < q; ++i) {
        char c;
        int a, b;
        scanf("%c %d %d\n", &c, &a, &b);
        if (c == '?') {
            if (ds.same(a, b))
                puts("yes");
            else
                puts("no");
        } else {
            ds.merge(a, b);
        }
    }
}
