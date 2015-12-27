#include <iostream>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int n, k;
        scanf("%d %d", &n, &k);
        int light_each = 1 << n;
        if ((k + 1) % light_each == 0)
            printf("Case #%d: ON\n", i);
        else
            printf("Case #%d: OFF\n", i);
    }
}
