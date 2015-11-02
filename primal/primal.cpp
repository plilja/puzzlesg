#include <iostream>
#include <vector>
#include "factorization.h"
#include <cmath>

using namespace std;

typedef vector<int> vi;

vi intersect(vi &s1, vi &s2)
{
    vi r;
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end() && it2 != s2.end()) {
        if (*it1 == *it2) {
            r.push_back(*it1);
            it1++;
            it2++;
        } else if (*it1 < *it2) {
            it1++;
        } else {
            it2++;
        }
    }
    return r;
}

int largest(vi &s)
{
    if (s.empty())
        return 0;
    return *s.rbegin();
}

vector<vi> all_prime_factors(vi &nums)
{
    vector<vi> pfs(nums.size());
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] == 1) {
            pfs[i] = vi();
        } else {
            pfs[i] = prime_factors(nums[i]);
        }
    }
    return pfs;
}

int solve(vi &nums, int k)
{
    vector<vi> m(nums.size() + 1, vi(k, 0));

    vector<vi> pfs = all_prime_factors(nums);
    int last = nums.size() - 1;
    m[last][0] = largest(pfs[last]);
    vi acc = pfs[last];
    for (int i = last - 1; i >= 0; --i) {
        acc = intersect(pfs[i], acc);
        m[i][0] = largest(acc);
    }

    vector<int> lims(nums.size() + 1, k - 1);

    for (int j = last - 1; j >= 0; --j) {
        vi pf = pfs[j];
        for (int h = j; h < (int)nums.size() - 1; ++h) {
            if (lims[j] == 0)
                break;
            if (h > j)
                pf = intersect(pf, pfs[h]);

            int x = largest(pf);
            for (int i = lims[j]; i >= 1; --i) {
                int y = m[h + 1][i - 1];
                int tmp = min(x, y);
                m[j][i] = max(tmp, m[j][i]);
                if (x == tmp) {
                    lims[j] = i - 1;
                }
            }
        }
    }
    return m[0][k - 1];
}

int main()
{
    int n, k;
    while (2 == scanf("%d %d", &n, &k)) {
        vi nums(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        int r = solve(nums, k);
        printf("%d\n", r);
    }
}
