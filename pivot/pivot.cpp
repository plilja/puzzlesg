#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    unordered_map<ll, bool> poss;
    ll running_max = numeric_limits<ll>::min();
    for (int i = 0; i < n; ++i) {
        ll c = a[i];
        if (c > running_max)
            poss[c] = true;
        else
            poss[c] = false;

        running_max = max(running_max, c);
    }

    ll running_min = numeric_limits<ll>::max();
    for (int i = n - 1; i >= 0; --i) {
        ll c = a[i];
        if (c < running_min && poss[c])
            poss[c] = true;
        else
            poss[c] = false;

        running_min = min(running_min, c);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (poss[a[i]])
            ans++;
    }
    printf("%d\n", ans);
}
