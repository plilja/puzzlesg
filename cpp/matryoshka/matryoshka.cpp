#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 100000000;

int f(vector<int> &v, int a, int b, vector<vector<int>> &f_cache, vector<vector<int>> &mins) {
    if (f_cache[a][b] != -1) {
        return f_cache[a][b];
    } else if (b - a == 0) {
        return 0;
    } else if (b - a == 1) {
        return 1;
    } else {
        int r = INF;
        for (int i = a; i < b; ++i) {
            int s = 0;
            s += f(v, a, i, f_cache, mins);
            s += f(v, i + 1, b, f_cache, mins);
            int min1 = mins[a][i];
            int min2 = mins[i + 1][b];
            if (min1 > min2) {
                s = s + i - a + 1;
            } else {
                for (int j = a; j <= i; ++j) {
                    if (v[j] > min2) {
                        ++s;
                    }
                }
            }
            if (min2 > min1) {
                s = s + b - i;
            } else {
                for (int j = i + 1; j <= b; ++j) {
                    if (v[j] > min1) {
                        ++s;
                    }
                }
            }
            r = min(r, s);
        }

        f_cache[a][b] = r;
        return r;
    }
}

int g(vector<int> &v, int i, vector<int> &g_cache, vector<vector<int>> &f_cache, vector<vector<int>> &mins) {
    if (i == v.size()) {
        return 0;
    } else if (g_cache[i] != -1) {
        return g_cache[i];
    } else {
        int r = INF;
        set<int> s1;
        set<int> s2;
        for (int j = i; j < v.size(); ++j) {
            if (s2.count(v[j])) {
                g_cache[i] = r;
                return r;
            }
            s1.insert(j - i + 1);
            s2.insert(v[j]);
            if (s1.size() == s2.size() && *s1.rbegin() == *s2.rbegin()) {
                r = min(r, f(v, i, j, f_cache, mins) + g(v, j + 1, g_cache, f_cache, mins));
            }
        }
        g_cache[i] = r;
        return r;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v[i] = a;
    }
    vector<vector<int>> mins(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        mins[i][i] = v[i];
        for (int j = i + 1; j < n; ++j) {
            mins[i][j] = min(mins[i][j - 1], v[j]);
        }
    }

    vector<vector<int>> f_cache(n + 1, vector<int>(n + 1, -1));

    vector<int> g_cache(n + 1, -1);
    int r = g(v, 0, g_cache, f_cache, mins);
    if (r < INF) {
        printf("%d\n", r);
    } else {
        puts("impossible");
    }
}
