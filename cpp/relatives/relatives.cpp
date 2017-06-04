#include <iostream>
#include <cmath>
#include "factorization.h"

using namespace std;

int totient(int n) {
    double r = n;
    for (int p : prime_factors(n)) {
        r *= 1 - 1 / ((double) p);
    }
    return (int) round(r);
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        int r = totient(n);
        printf("%d\n", r);
    }
}
