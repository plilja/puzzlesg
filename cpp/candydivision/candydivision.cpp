#include "factorization.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> all_divisors(ll n, vector<ll> prime_factors = vector<ll>(), int i = 0)
{
    if (prime_factors.empty()) {
        prime_factors = factorization(n);
    }
    if (i == (int)prime_factors.size()) {
        vector<ll> res;
        res.push_back(1);
        return res;
    }
    vector<ll> powers;
    ll acc = 1;
    ll p = prime_factors[i];
    while (n % (acc * p) == 0) {
        acc *= p;
        powers.push_back(acc);
        i++;
    }
    vector<ll> res;
    auto sub = all_divisors(n / acc, prime_factors, i);
    for (auto f : sub) {
        res.push_back(f);
        for (auto pp : powers) {
            res.push_back(f * pp);
        }
    }
    return res;
}

vector<ll> solve(ll n)
{
    auto divs = all_divisors(n);
    vector<ll> res;
    for (auto d : divs) {
        res.push_back(d - 1);
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    long long n;
    while (1 == scanf("%lld", &n)) {
        for (auto f : solve(n)) {
            printf("%lld ", f);
        }
        puts("");
    }
}
