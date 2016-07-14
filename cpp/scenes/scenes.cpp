#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll M = 1000000007;

ll f(ll n, ll w, ll h, vector<vector<ll>> &c) {
    if (w == 0) {
        return 1;
    }
    if (c[w][n] != -1) {
        return c[w][n];
    }
    ll a = 0;
    ll t = min(h, n);
    for (int i = 0; i <= t; ++i) {
        a += f(n - i, w - 1, h, c);
        a %= M;
    }
    c[w][n] = a;
    return a;
}

ll solve(ll n, ll w, ll h) {
    vector<vector<ll>> c(w + 1, vector<ll>(n + 1, -1));
    ll a = f(n, w, h, c);
    for (int i = 0; i <= h; ++i) {
        if (w * i <= n) {
            a -= 1;
        }
    }
    a = (a + M) % M;
    return a;
}

int main() {
    ll n, w, h;
    scanf("%lld %lld %lld", &n, &w, &h);
    ll a = solve(n, w, h);
    printf("%llu\n", a);
}
