#include <iostream>
#include <vector>
#include <cmath>
#include "factorization.h"

using namespace std;

int MAX = 10000;

/**
 * Euler's totient function.
 */
int phi(int n) {
    auto pf = prime_factors(n);
    int ans = n;
    for (auto p : pf) {
        ans *= (1 - 1 / ((double) p));
    }
    return (int) round(ans);
}

int main() {
    vector<int> m(MAX + 1, 0);
    m[1] = 2; // 0/1, 1/1
    for (int i = 2; i <= MAX; ++i) {
        m[i] = m[i - 1] + phi(i);
    }
    int p;
    scanf("%d", &p);
    for (int _ = 0; _ < p; ++_) {
        int k, n;
        scanf("%d %d", &k, &n);
        printf("%d %d\n", k, m[n]);
    }
}
