#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

double EPS = 1e-9;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    vector<ll> ts(m);
    for (int i = 0; i < m; ++i) {
        scanf("%lld", &ts[i]);
    }
    vector<ll> xs;
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        xs.push_back(x);
    }
    set<ll> ans;
    for (int i = 0; i < n - m + 1; ++i) {
        double d = xs[i + 1] - xs[i];
        double v = d/(ts[1] - ts[0]);
        bool valid = true;
        for (int j = i + 1; j < i + m && valid; ++j) {
            ll dt = ts[j - i] - ts[0];
            ll exp = xs[i] + dt * v + EPS;
            valid = valid && exp == xs[j];
        }
        if (valid) {
            ans.insert(d);
        }
    }
    printf("%lu\n", ans.size());
    for (auto d : ans) {
        printf("%lld ", d);
    }
    printf("\n");
}
