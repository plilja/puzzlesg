#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> pii;

bool byFirstAndThenBySize(const pii &a, const pii &b)
{
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

vector<pii> solve(vector<pii> &intervals, int n)
{
    sort(intervals.begin(), intervals.end(), byFirstAndThenBySize);
    map<int, map<int, int>> M;

    int best = 0, best_idx = -1;
    vector<int> pre(n, -1);
    for (int i = 0; i < n; ++i) {
        auto &iv = intervals[i];
        int a = 0, b = best, p = -1;
        while (a < b) {
            int middle = (a + b + 1) / 2;
            auto it1 = M.lower_bound(middle);
            if (it1 == M.end()) {
                b = middle - 1;
                continue;
            }
            auto it2 = it1->second.lower_bound(iv.second);
            if (it2 == it1->second.end()) {
                b = middle - 1;
            } else {
                a = middle;
                p = it2->second;
            }
        }
        int r = a + 1;
        pre[i] = p;
        M[r][iv.second] = i;
        if (r > best) {
            best_idx = i;
            best = r;
        }
    }
    vector<pii> res(best);
    int i = best - 1;
    int idx = best_idx;
    while (idx != -1) {
        res[i] = intervals[idx];
        --i;
        idx = pre[idx];
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pii> intervals;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        intervals.push_back({a, b});
    }

    auto ans = solve(intervals, n);

    printf("%d\n", (int)ans.size());
    for (auto &iv : ans) {
        printf("%d %d\n", iv.first, iv.second);
    }
}
