#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int helper(vector<string> &input, vector<char> &remaining_chars, vector<char> &assigned_chars, vector<int> &m, int n)
{
    if (remaining_chars.empty()) {
        for (auto &s : input) {
            if (m[s[0] - 'A'] == 0) {
                return 0;
            }
        }
        int a = 0;
        for (int i = 0; i < n; ++i) {
            string &s = input[i];
            int k = 0;
            for (char c : s) {
                assert(m[c - 'A'] != -1);
                k = 10 * k + m[c - 'A'];
            }
            int fact = i == n - 1 ? -1 : 1;
            a = a + fact * k;
        }
        return a == 0 ? 1 : 0;
    } else {
        int ans = 0;
        char c = remaining_chars.back();
        remaining_chars.pop_back();
        assigned_chars.push_back(c);
        for (int i = 0; i < 10; ++i) {
            bool free = true;
            for (char ass : assigned_chars) {
                if (m[ass - 'A'] == i) {
                    free = false;
                    break;
                }
            }
            if (free) {
                m[c - 'A'] = i;
                ans += helper(input, remaining_chars, assigned_chars, m, n);
                m[c - 'A'] = -1;
            }
        }
        remaining_chars.push_back(c);
        assigned_chars.pop_back();
        return ans;
    }
}

int solve(vector<string> &input, int n)
{
    vector<char> remaining_chars;
    for (string &s : input) {
        for (char c : s) {
            bool present = false;
            for (char c2 : remaining_chars) {
                if (c == c2) {
                    present = true;
                }
            }
            if (!present) {
                remaining_chars.push_back(c);
            }
        }
    }
    vector<char> assigned_chars;
    vector<int> m(27, -1);
    return helper(input, remaining_chars, assigned_chars, m, n);
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int r = solve(v, n);
    cout << r << endl;
}
