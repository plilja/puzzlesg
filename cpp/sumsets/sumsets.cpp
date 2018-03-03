#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

pair<bool, int> solve(vector<int> &v, int n) {
    unordered_map<int, vector<pair<int, int>>> two_sums;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            two_sums[v[i] + v[j]].push_back({i, j});
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int d = v[i];
        for (int j = n - 1; j >= 0; --j) {
            if (i == j) {
                continue;
            }
            int c = v[j];
            int a_plus_b = d - c;
            auto it = two_sums.find(a_plus_b);
            if (it != two_sums.end()) {
                for (auto &p : it->second) {
                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        return {true, d};
                    }
                }
            }
        }
    }
    return {false, 0};
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    auto r = solve(v, n);
    if (r.first) {
        printf("%d\n", r.second);
    } else {
        puts("no solution");
    }
}
