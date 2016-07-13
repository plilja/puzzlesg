#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

vector<int> factorization(int x) {
    assert(x > 1);
    vector<int> ans;
    while (x % 2 == 0) {
        ans.push_back(2);
        x /= 2;
    }
    int upper_lim = sqrt(x);
    for (int i = 3; i <= upper_lim; i += 2) {
        bool redefine_limit = false;
        while (x % i == 0) {
            ans.push_back(i);
            x /= i;
            redefine_limit = true;
        }
        if (redefine_limit) {
            upper_lim = sqrt(x);
        }

    }
    if (x > 1) {
        ans.push_back(x);
    }

    return ans;
}

ll solve(int n, int k, vector<vector<int>> &facts) {
    vector<int> v(n + 1, 0);
    for (int i = max(n - k + 1, 2); i <= n; ++i) {
        for (auto p : facts[i]) {
            v[p] += 1;
        }
    }
    for (int i = 2; i <= k; ++i) {
        for (auto p : facts[i]) {
            v[p] -= 1;
        }
    }
    ll a = 1;
    for (int j = 0; j <= n; ++j) {
        a = a * (v[j] + 1);
    }
    return a;
}

int main() {
    vector<vector<int>> facts(433);
    for (int i = 2; i < 433; ++i) {
        facts[i] = factorization(i);
    }
    int n, k;
    while (2 == scanf("%d %d", &n, &k)) {
        ll a = solve(n, k, facts);
        printf("%llu\n", a);
    }
}
