#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;

ll fact(int n)
{
    ll r = 1;
    for (int i = 1; i <= n; ++i) {
        r *= i;
    }
    return r;
}

ll num_combos(string w)
{
    map<char, int> count;
    for (auto c : w) {
        count[c]++;
    }
    ll total_num = fact(w.size());
    for (auto kv : count) {
        total_num /= fact(kv.second);
    }
    return total_num;
}

string solve_helper(string &w_sorted, ll k)
{
    if (w_sorted.size() == 1) {
        assert(k == 0);
        return w_sorted;
    }
    ll j = 0;
    for (int i = 0; i < (int)w_sorted.size(); ++i) {
        char c = w_sorted[i];
        if (i > 0 && w_sorted[i - 1] == w_sorted[i]) {
            continue;
        }
        string w_except_c = w_sorted.substr(0, i) + w_sorted.substr(i + 1, w_sorted.size() - i);
        ll t = num_combos(w_except_c);

        if (j <= k && j + t > k) {
            return c + solve_helper(w_except_c, k - j);
        }
        j += t;
    }
    return w_sorted;
}

string solve(string &w, ll k_one_indexed)
{
    string w_sorted = w;
    sort(w_sorted.begin(), w_sorted.end());
    return solve_helper(w_sorted, k_one_indexed - 1);
}

int main()
{
    while (true) {
        string w;
        ll k;
        cin >> w >> k;
        if (k == 0)
            break;
        string r = solve(w, k);
        cout << r << endl;
    }
}
