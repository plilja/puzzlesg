#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

bool possible(multiset<ll> &s) {
    for (ll a : s) {
        for (ll b : s) {
            if (a == b && s.count(a) == 1) {
                continue;
            }
            ll minC = max(a, b) - min(a, b) + 1;
            ll maxC = a + b - 1;
            auto it = s.lower_bound(minC);
            while (it != s.end() && *it <= maxC) {
                ll c = *it;
                int count = 1;
                if (c == a || c == b) {
                    count++;
                    if (a == b) {
                        count++;
                    }
                }
                if (s.count(c) >= count) {
                    return true;
                }
                it++;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    multiset<ll> s;
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        s.insert(x);
    }
    if (possible(s)) {
        puts("possible");
    } else {
        puts("impossible");
    }
}
