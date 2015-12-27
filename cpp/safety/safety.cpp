#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double EPS = 10e-10;

double solve(vector<pair<int, int>> &contestants_sorted, vector<int> contestants, int idx, int X)
{
    int jury = contestants[idx];
    double a = 0.0, b = 1.0;
    while (b - a > EPS) {
        double m = (b + a) / 2;
        double score = jury + X * m;
        double s = 0;
        for (auto c : contestants_sorted) {
            if (c.second == idx)
                continue;
            if (c.first > score - EPS)
                break;
            s += (score - c.first) / X - EPS;
        }
        if (s + m > 1.0) {
            b = m;
        } else {
            a = m;
        }
    }
    return a;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; ++c) {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> contestants_sorted;
        vector<int> contestants(n);
        int X = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &contestants[i]);
            contestants_sorted.push_back({contestants[i], i});
            X += contestants[i];
        }
        sort(contestants_sorted.begin(), contestants_sorted.end());

        printf("Case #%d:", c);
        for (int i = 0; i < n; ++i) {
            double perc = 100 * solve(contestants_sorted, contestants, i, X);
            printf(" %.6lf", perc);
        }
        puts("");
    }
}
