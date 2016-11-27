#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

typedef pair<double, double> pdd;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, l, t;
        scanf("%d %d %d", &n, &l, &t);
        vector<vector<double>> strengths(2, vector<double>(n));
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &strengths[0][i]);
        }
        vector<vector<pdd>> links(n);
        vector<set<int>> neighbours(n);
        for (int i = 0; i < l; ++i) {
            int a, b;
            double p;
            scanf("%d %d %lf", &a, &b, &p);
            links[a].push_back({b, p});
            if (a != b) {
                neighbours[a].insert(b);
                neighbours[b].insert(a);
            }
        }
        for (int i = 1; i <= t; ++i) {
            for (int j = 0; j < n; ++j) {
                strengths[i % 2][j] = strengths[(i - 1) % 2][j];
            }
            for (int j = 0; j < n; ++j) {
                for (auto link : links[j]) {
                    strengths[i % 2][link.first] += strengths[(i - 1) % 2][j] * link.second;
                    strengths[i % 2][j] -= strengths[(i - 1) % 2][j] * link.second;
                }
            }
        }
        double ans = numeric_limits<double>::infinity();
        for (int i = 0; i < n; ++i) {
            double strength = strengths[t % 2][i];
            for (int neighbour : neighbours[i]) {
                strength += strengths[t % 2][neighbour];
            }
            ans = min(ans, strength);
        }
        printf("%.9lf\n", ans);
    }
}