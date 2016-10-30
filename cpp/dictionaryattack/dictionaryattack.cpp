#include <iostream>
#include <vector>

using namespace std;

bool helper(string &w, string &p, int diff, int dig, int rem) {
    if (diff == dig) {
        return rem >= dig;
    }
    if (rem == 0) {
        return false;
    }
    if (diff - dig > 2 * (rem - dig)) {
        return false;
    }
    for (int i = 0; i < p.size() - 1; ++i) {
        int corr = 0;
        if (w[i + 1] == p[i]) {
            corr++;
        }
        if (w[i] == p[i + 1]) {
            corr++;
        }
        if (w[i] == p[i]) {
            corr--;
        }
        if (w[i + 1] == p[i + 1]) {
            corr--;
        }
        string p1 = p;
        swap(p[i], p[i + 1]);
        bool b = helper(w, p, diff - corr, dig, rem - 1);
        swap(p[i], p[i + 1]);
        if (b) {
            return true;
        }
    }
    return false;
}

bool three_simple(string &w, string &p) {
    if (w.size() != p.size()) {
        return false;
    }
    int diff = 0;
    int dig = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != w[i]) {
            diff++;
        }
        if (p[i] >= '0' && p[i] <= '9') {
            dig++;
        }
    }
    return helper(w, p, diff, dig, 3);
}

int main() {
    int n;
    cin >> n;
    vector<string> dict;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dict.push_back(s);
    }
    string pass;
    while (cin >> pass) {
        bool good = true;
        for (auto &w : dict) {
            if (three_simple(w, pass)) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << pass << endl;
        }
    }
}
