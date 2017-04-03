#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

double EPS = 1e-12;

struct Bug {
    double prob;
    double severity;
    int id;
    int attempts;

    bool operator <(const Bug& b2) const {
        double exp_gain1 = prob * severity;
        double exp_gain2 = b2.prob * b2.severity;
        if (abs(exp_gain1 - exp_gain2) < EPS) {
            return b2.attempts < attempts;
        } else {
            return exp_gain1 < exp_gain2;
        }
    }
};

int num_bits_set(int a) {
    int r = 0;
    while (a) {
        r += (a & 1);
        a >>= 1;
    }
    return r;
}

bool cmp_bits_set(int a, int b) {
    return num_bits_set(a) < num_bits_set(b);
}

vector<int> range(int a, int b) {
    vector<int> r(b - a);
    for (int i = a; i < b; ++i) {
        r[i - a] = i;
    }
    return r;
}

double solve(vector<Bug> &bugs, int B, int T, double f) {
    int lim = (int) pow(2, B);
    vector<int> subsets = range(0, lim);
    sort(subsets.begin(), subsets.end(), cmp_bits_set);

    // m[subset] stores all possible bug states that can be achieved by trying bugs from 
    // "subset" 0 to T times repeatedly. The bug states are stored sorted by expected return. 
    vector<vector<Bug>> m(lim);
    for (int subset : subsets) {
        for (int j = 0; j < B; ++j) {
            if (subset & (1 << j)) {
                Bug b = bugs[j];
                for (int k = 0; k < T && b.prob * b.severity > 100*EPS; ++k) {
                    m[subset].push_back(b);
                    b.attempts += 1;
                    b.prob *= f;
                }
            }
        }
        sort(m[subset].begin(), m[subset].end());
        reverse(m[subset].begin(), m[subset].end());
    }

    // w[subset][t][k] stores the expected return when the subset of bugs indicated by "subset" remains,
    // time t remains, and k attempts have already been made on the given subset.
    vector<vector<vector<double>>> w(lim, vector<vector<double>>(T + 1, vector<double>(T + 1, 0)));
    for (int subset : subsets) {
        for (int t = 1; t <= T; ++t) {
            for (int k = min(T, (int) m[subset].size() - 1); k >= 0; --k) {
                Bug &b = m[subset][k];
                assert(b.attempts <= k);
                int next_subset = subset ^ (1 << b.id);
                double r = b.prob * (b.severity + w[next_subset][t - 1][k - b.attempts]);
                if (k < T) {
                    r += (1 - b.prob) * w[subset][t - 1][k + 1];
                }
                w[subset][t][k] = r;
            }
        }
    }
    return w[lim - 1][T][0];
}

int main()
{
    int B, T;
    double f;
    while (3 == scanf("%d %d %lf", &B, &T, &f)) {
        vector<Bug> bugs;
        for (int i = 0; i < B; ++i) {
            double p, s;
            scanf("%lf %lf", &p, &s);
            bugs.push_back(Bug({p, s, i, 0}));
        }
        double ans = solve(bugs, B, T, f);
        printf("%.6lf\n", ans);
    }
}
