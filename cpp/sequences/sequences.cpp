#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int ll;

ll M = 1000000007;

ll modpow(ll num, ll exp, ll mod) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return num;
    } else {
        ll subRes = modpow(num, exp / 2, mod);
        ll res = (subRes * subRes) % mod;
        if (exp % 2 == 1) {
            res = (res * num) % mod;
        } 
        return res;
    }
}

ll solve(char *s, int n) {
    ll qs = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            qs++;
        }
    }
    ll qf0 = modpow(2, qs, M);
    ll qf1 = modpow(2, qs - 1, M);

    ll qsRem = qs;
    ll ans = 0;
    ll ones = 0;
    ll maybeOnes = 0;
    ll f = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones++;
        } else if (s[i] == '?') {
            ans = (ans + qf1 * ones) % M; 
            ans = (ans + maybeOnes * modpow(2, qsRem - 1, M)) % M;

            maybeOnes = (2 * maybeOnes + f) % M;
            f = (2 * f) % M;
            qsRem--;
        } else {
            // s[i] == 0
            ans = (ans + qf0 * ones) % M; 
            ans = (ans + maybeOnes * modpow(2, qsRem, M)) % M;
        }
    }
    return ans;
}

int main()
{
    char s[500003];
    scanf("%s", s);
    int n = strlen(s);
    ll r = solve(s, n);
    printf("%lld\n", r);
}
