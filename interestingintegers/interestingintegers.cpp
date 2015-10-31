#include "gcd.h"
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll LIM = 1e9;

vector<ll> fibonaccis()
{
    ll fn1 = 1;
    ll fn2 = 1;
    vector<ll> r;
    r.push_back(fn1);
    r.push_back(fn2);
    while (true) {
        ll tmp = fn1 + fn2;
        if (tmp > LIM)
            break;
        fn1 = fn2;
        fn2 = tmp;
        r.push_back(tmp);
    }
    return r;
}

int main()
{
    auto fibs = fibonaccis();
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        ll best_a = LIM + 1;
        ll best_b = LIM + 1;
        for (int i = fibs.size() - 1; i >= 1; --i) {
            auto fib1 = fibs[i - 1];
            auto fib2 = fibs[i];
            auto r = extendedGcd(fib1, fib2);
            int b = (r.b * (n / r.gcd % fib1)) % fib1;
            if (b < 0) {
                b += fib1;
            }
            auto a = LIM;
            while (b <= best_b && a > 0) {
                a = (n - b * fib2) / fib1;
                if (a <= b && a * fib1 + b * fib2 == n) {
                    break;
                }
                b += fib1;
            }
            if (a > 0 && a * fib1 + b * fib2 == n) {
                if (b < best_b || (b == best_b && a < best_a)) {
                    best_a = a;
                    best_b = b;
                }
            }
        }
        printf("%lld %lld\n", best_a, best_b);
    }
}
