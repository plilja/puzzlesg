#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll solve(int steps, int twoOneBalance, int oneBalance, int twoBalance, map<pair<pii, pii>, ll> &cache, bool left) {
    pair<pii, pii> key = {{steps, twoOneBalance}, {oneBalance, twoBalance}};
    auto it = cache.find(key);
    if (it != cache.end()) {
        return it->second;
    }
    if (twoOneBalance > steps/2 || abs(oneBalance) > steps || abs(twoBalance) > steps / 2) {
        return 0;
    }
    if (steps == 0) {
        if (twoOneBalance <= 0) {
            return 1;
        } else {
            return 0;
        }
    }
    ll ans = 0;
    if (left) {
        ans += solve(steps - 1, twoOneBalance + 1, oneBalance - 1, twoBalance, cache, false);
        if (steps > 1) {
            ans += solve(steps - 2, twoOneBalance - 1, oneBalance, twoBalance - 1, cache, false);
        }
    } else {
        ans += solve(steps - 1, twoOneBalance + 1, oneBalance + 1, twoBalance, cache, true);
        if (steps > 1) {
            ans += solve(steps - 2, twoOneBalance - 1, oneBalance, twoBalance + 1, cache, true);
        }
    }
    cache[key] = ans;
    return ans;
}

int main() 
{
    map<pair<pii, pii>, ll> cache;
    int p;
    scanf("%d", &p);
    for (int _ = 0; _ < p; ++_) {
        int i, s;
        scanf("%d %d", &i, &s);
        printf("%d %lld\n", i, solve(s, 0, 0, 0, cache, true));
    }
}
