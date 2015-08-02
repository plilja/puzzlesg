#include <iostream>

using namespace std;

long long solve(long long t, long long K)
{
    if (t < 2 * K) {
        return t;
    } else {
        return K + 1 + (t % K);
    }
}

int main()
{
    long long n, K;
    while (2 == scanf("%lld %lld", &n, &K)) {
        printf("%lld\n", solve(n - 1, K));
    }
}
