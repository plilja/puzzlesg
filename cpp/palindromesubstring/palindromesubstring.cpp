#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> solve(string s) {
    set<string> r;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int j;
        for (int j_ = 0; j_ < min(i + 1, n - i); ++j_) {
            if (s[i - j_] != s[i + j_]) {
                break;
            }
            j = j_;
        }
        if (j >= 1) {
            for (int k = 1; k < j + 1; k++) {
                r.insert(s.substr(i - k, 2 * k + 1));
            }
        }

        j = -1;
        for (int j_ = 0; j_ < min(i + 1, n - i - 1); ++j_) {
            if (s[i - j_] != s[i + j_ + 1]) {
                break;
            }
            j = j_;
        }
        if (j >= 0) {
            for (int k = 0; k < j + 1; k++) {
                r.insert(s.substr(i - k, 2 * k + 2));
            }
        }
    }
    return r;
}

int main() {
    char s[1004];
    while (1 == scanf("%s", s)) {
        auto r = solve(s);
        for (auto &p : r) {
            printf("%s\n", p.c_str());
        }
        printf("\n");
    }
}
