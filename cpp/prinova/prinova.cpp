#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool is_odd(int t) {
    return t % 2 == 1;
}

bool in_range(int a, int b, int t) {
    return t == min(b, max(a, t));
}

int solve(int a, int b, int n, vector<int> &boys) {
    sort(boys.begin(), boys.end());
    vector<int> candidates;
    candidates.push_back(a);
    candidates.push_back(a + 1);
    candidates.push_back(b);
    candidates.push_back(b - 1);
    for (int i = 0; i < n - 1; ++i) {
        int half = boys[i] + (boys[i + 1] - boys[i]) / 2;
        candidates.push_back(half);
        candidates.push_back(half - 1);
        candidates.push_back(half + 1);
    }
    int best = -1;
    int best_d = -1;
    for (int t : candidates) {
        if (is_odd(t) && in_range(a, b, t)) {
            int d = numeric_limits<int>::max();
            for (int boy : boys) {
                d = min(d, abs(boy - t));
            }
            if (d > best_d) {
                best = t;
                best_d = d;
            }
        }
    }
    return best;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> boys(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &boys[i]);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    int r = solve(a, b, n, boys);
    printf("%d\n", r);
}
