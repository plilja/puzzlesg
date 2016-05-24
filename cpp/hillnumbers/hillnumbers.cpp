#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int digit(char c) {
    return (int) (c - '0');
}

ll helper(int prev, int rem, bool inc, vector<vector<ll>> &cache1, vector<vector<ll>> &cache2) {
    if (rem == 0) {
        return 1;
    }
    if (inc) {
        if (cache1[prev][rem] != -1) {
            return cache1[prev][rem];
        }
    } else {
        if (cache2[prev][rem] != -1) {
            return cache2[prev][rem];
        }
    }

    ll ans = 0;
    for (int i = 0; i < prev; ++i) {
        ans += helper(i, rem - 1, false, cache1, cache2);
    }
    ans += helper(prev, rem - 1, inc, cache1, cache2);
    if (inc) {
        for (int i = prev + 1; i < 10; ++i) {
            ans += helper(i, rem - 1, true, cache1, cache2);
        }
    }
    if (inc) {
        cache1[prev][rem] = ans;
    } else {
        cache2[prev][rem] = ans;
    }
    return ans;
}

ll solve(string &s) {
    vector<vector<ll>> cache1(10, vector<ll>(19, -1));
    vector<vector<ll>> cache2(10, vector<ll>(19, -1));
    int len = (int) s.size();
    ll ans = 0;
    bool inc = true;
    int prev = 0;
    for (int i = 0; i < len; ++i) {
        int d = digit(s[i]);
        if (d < prev) {
            inc = false;
        } else if (!inc && d > prev) {
            return -1;
        }
        for (int j = 0; j < d; ++j) {
            ans += helper(j, len - i - 1, inc && j >= prev, cache1, cache2);
        }
        prev = d;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
