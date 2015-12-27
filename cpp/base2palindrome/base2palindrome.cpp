#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull solve(int M)
{
    vector<vector<ull>> r(2, vector<ull>());
    r[0].push_back(0);
    r[0].push_back(1);
    r[1].push_back(0);
    r[1].push_back(3);
    int level = 2;
    int nums_generated = 2;
    while (nums_generated <= M) {
        int p = level % 2 == 0 ? 0 : 1;
        r.push_back(vector<ull>());
        while (p < level) {
            for (auto n : r[p]) {
                ull t = (1 << level) | (n << (level - p) / 2) | 1;
                r[level].push_back(t);
                nums_generated++;
            }
            p += 2;
        }
        level++;
    }
    int c = 0;
    for (auto &v : r) {
        for (auto g : v) {
            if (g != 0)
                c++;
            if (c == M)
                return g;
        }
    }
    return 0;
}

int main()
{
    int M;
    scanf("%d", &M);
    auto r = solve(M);
    printf("%llu\n", r);
}
