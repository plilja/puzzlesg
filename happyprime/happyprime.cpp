#include <iostream>
#include <vector>
#include "primesieve.h"

using namespace std;

typedef vector<bool> vb;

vector<int> digits(int m)
{
    vector<int> r;
    while (m > 0) {
        r.push_back(m % 10);
        m /= 10;
    }
    return r;
}

bool redToOne(int m, vb &cache, vb &vis)
{
    if (vis[m]) {
        return cache[m];
    }

    int mp = 0;
    for (int d : digits(m)) {
        mp += d * d;
    }
    vis[m] = true;
    cache[m] = false;
    bool ans = redToOne(mp, cache, vis);
    vis[m] = true;
    cache[m] = ans;
    return ans;
}

int main()
{
    PrimeSieve ps(10000);
    vb vis(10001, false);
    vb cache(10001);
    cache[1] = true;
    vis[1] = true;

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int k, m;
        scanf("%d %d", &k, &m);
        if (ps.isPrime(m) && redToOne(m, cache, vis))
            printf("%d %d YES\n", k, m);
        else
            printf("%d %d NO\n", k, m);
    }
}
