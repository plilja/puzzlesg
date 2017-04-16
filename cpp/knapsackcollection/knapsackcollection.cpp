#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include "gcd.h"

using namespace std;

typedef long long ll;

int main()
{
    int n, s, t;
    scanf("%d %d %d", &n, &s, &t);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    map<int, ll> times;
    for (int i = 0; i < n; ++i) {
        if (times.count(v[i]) > 0) {
            continue;
        }
        multiset<int> knapsacks;
        for (auto k : v) {
            knapsacks.insert(k);
        }
        ll pos = v[i];
        ll time = 0;
        for (int j = 0; j < n; ++j) {
            auto it = knapsacks.lower_bound(pos);
            int wait;
            if (it == knapsacks.end()) {
                auto it2 = knapsacks.begin();
                wait = s - (pos - *it2);
                knapsacks.erase(it2);
            } else {
                wait = *it - pos;
                knapsacks.erase(it);
            }
            time = time + wait + t;
            pos = (pos + wait + t) % s;
        }
        times[v[i]] = time;
    }
    ll minimum = ((ll)n) * (s + t + 1);
    ll maximum = 0;
    ll sum = 0;
    for (int i = 0; i < s; ++i) {
        auto it = times.lower_bound(i);
        ll time;
        if (it == times.end()) {
            auto it2 = times.begin();
            time = s - i + it2->first + it2->second;
        } else {
            time = it->first - i + it->second;
        }
        minimum = min(minimum, time);
        maximum = max(maximum, time);
        sum += time;
    }
    ll g = gcd<ll>(sum, s);
    printf("%lld\n", minimum);
    printf("%lld\n", maximum);
    printf("%lld/%lld\n", sum/g, s/g);
}
