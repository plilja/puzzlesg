#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval {
    int from, to, box;
};

bool cmp(const Interval &a, const Interval &b) {
    return a.from < b.from;
}

/**
 * Projects the boxes onto intervals. Boxes that are contained in other boxes
 * will be intervals contained in other intervals. Intervals will be completely
 * non overlapping (i.e they will either be fully contained in another interval
 * or completely disjoined).
 */
void project(vector<vector<int>> &v, vector<Interval> &res, vector<int> &roots) {
    deque<int> q;
    for (auto root : roots) {
        q.push_back(root);
    }
    int free = 0;
    vector<int> starts(v.size(), -1);
    while (!q.empty()) {
        int t = q.front();

        if (starts[t] == -1) {
            starts[t] = free;
            free += 1;
        }
        bool childrenDone = true;
        for (auto child : v[t]) {
            if (starts[child] == -1) {
                q.push_front(child);
                childrenDone = false;
            }
        }
        if (childrenDone) {
            res.push_back(Interval({starts[t], free, t}));
            free += 1;
            q.pop_front();
        }
    }

}

int binarySearch(vector<Interval> &intervals, int target, int lower, int upper) {
    while (lower < upper) {
        int m = lower + (upper - lower + 1) / 2;
        if (intervals[m].from > target) {
            upper = m - 1;
        } else {
            lower = m;
        }
    }
    return lower;
}

bool encloses(Interval &a, Interval &b) {
    return a.from <= b.from && a.to >= b.to;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> v(n);
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (a == 0) {
            roots.push_back(i);
        } else {
            v[a - 1].push_back(i);
        }
    }

    vector<Interval> intervals;
    project(v, intervals, roots);
    sort(intervals.begin(), intervals.end(), cmp);

    vector<int> boxToInterval(n);
    for (int i = 0; i < n; ++i) {
        boxToInterval[intervals[i].box] = i;
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int m;
        scanf("%d", &m);
        vector<int> qs;
        for (int j = 0; j < m; ++j) {
            int a;
            scanf("%d", &a);
            a--;
            qs.push_back(a);
        }

        vector<int> topLevelQs;
        for (int j = 0; j < m; ++j) {
            bool keep = true;
            for (int k = 0; k < m; ++k) {
                if (encloses(intervals[boxToInterval[qs[k]]], intervals[boxToInterval[qs[j]]]) &&
                    (qs[k] != qs[j] || j > k)) {
                    keep = false;
                    break;
                }
            }
            if (keep) {
                topLevelQs.push_back(qs[j]);
            }
        }

        int ans = 0;
        for (auto b : topLevelQs) {
            int j = boxToInterval[b];
            ans = ans + binarySearch(intervals, intervals[j].to, j, intervals.size() - 1) - j + 1;
        }
        printf("%d\n", ans);
    }
}
