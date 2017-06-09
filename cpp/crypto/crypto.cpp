#include <iostream>
#include "factorization.h"

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 2;
    int best = 0;
    for (int pf : prime_factors(n)) {
        int k = 1;
        int d = pf;
        while (n % d == 0) {
            k++;
            d *= pf;
        }
        if (k > best) {
            best = k;
            ans = pf;
        }
    }
    printf("%d\n", ans);
}
