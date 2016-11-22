#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned int M = 540000000;

pair<bool, int> solve(vector<int> &v, int n) {
    vector<bool> two_sums(M*4, false);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            two_sums[v[i] + v[j] + 2*M] = true;
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
            if (two_sums[a_plus_b + 2*M]) {
                for (int k = 0; k < n; ++k) {
                    for (int h = 0; h < n; ++h) {
                        if (v[k] + v[h] == a_plus_b && k != h && j != k && j != h && i != k && i != h) {
                            return {true, d};
                        }
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
