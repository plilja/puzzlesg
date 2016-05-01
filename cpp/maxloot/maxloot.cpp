#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <cassert>

using namespace std;

typedef unsigned ui;

const ui INF = 2000000001;

int brute_force(int n, int cap, vector<int> &vs, vector<int> &cs) {
    assert(n < 32);
    int d1 = (n + 2 - 1) / 2;
    int d2 = n - d1;
    int lim1 = 1 << d1;
    int lim2 = 1 << d2;

    vector<pair<int, int>> cache1(lim1);
    vector<pair<int, int>> cache2(lim2);
    for (int i = 0; i < lim1; ++i) {
        bitset<32> b(i);
        int v = 0, c = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j]) {
                v += vs[j];
                c += cs[j];
            }
        }
        cache1[i] = {v, c};
    }
    for (int i = 0; i < lim2; ++i) {
        bitset<32> b(i);
        int v = 0, c = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j]) {
                v += vs[j + d1];
                c += cs[j + d1];
            }
        }
        cache2[i] = {v, c};
    }
    int res = 0;
    for (auto &p1 : cache1) {
        for (auto &p2 : cache2) {
            if (p1.second + p2.second <= cap) {
                res = max(res, p1.first + p2.first);
            }
        }
    }
    return res;
}

int sum(vector<int> &v) {
    int r = 0;
    for (auto i : v) {
        r += i;
    }
    return r;
}

int dyn_prog(int n, int cap, vector<int> &vs, vector<int> &cs) {
    int lim = sum(vs);
    vector<vector<unsigned int>> m(2, vector<unsigned int>(lim + 1, INF));
    m[0][0] = 0;
    m[1][0] = 0;

    // In the beginning of the dyn prog algo most elements in the m matrix will be INF
    // and we are better of just brute forcing.
    int brute_lim = 13;
    for (int k = 0; k < (1 << brute_lim); ++k) {
        bitset<32> b(k);
        int v = 0, c = 0;
        for (int j = 0; j < brute_lim; ++j) {
            if (b[j]) {
                v += vs[j];
                c += cs[j];
            }
        }
        m[brute_lim % 2][v] = min(m[brute_lim % 2][v], (ui)c);
    }

    for (int i = brute_lim + 1; i <= n; ++i) {
        int v = vs[i - 1];
        int c = cs[i - 1];
        for (int j = 0; j < v; ++j) {
            m[i % 2][j] = m[(i - 1) % 2][j];
        }
        for (int j = v; j <= lim; ++j) {
            m[i % 2][j] = min(m[(i - 1) % 2][j], m[(i - 1) % 2][j - v] + c);
        }
    }

    for (int j = lim; j > 0; --j) {
        if (m[n % 2][j] <= cap) {
            return j;
        }
    }
    return 0;
}

int solve(int n, int c, vector<int> &vs, vector<int> &cs) {
    if (n < 28) {
        // brute force solution will be fast when n is small
        return brute_force(n, c, vs, cs);
    } else {
        // dyn prog solution will be fast when sum(vs) is small
        // according to the inequality in the prob statement sum(vs) will be small when n is large
        return dyn_prog(n, c, vs, cs);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);
        vector<int> vs(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &vs[i]);
        }
        vector<int> cs(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cs[i]);
        }
        int r = solve(n, c, vs, cs);
        printf("%d\n", r);
    }
}
