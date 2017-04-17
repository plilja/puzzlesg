#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int keypad[][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -1}
};

void add_all(set<int> &target, const set<int> to_be_added) {
    for (int i : to_be_added) {
        target.insert(i);
    }
}

set<int> writables(int x, int y, int lim) {
    set<int> r;
    int d = keypad[y][x];
    if (lim > 0 && d != -1) {
        r.insert(d);
        if (d != 0) {
            set<int> sub = writables(x, y, lim / 10);
            if (x < 2) {
                add_all(sub, writables(x + 1, y, lim));
            }
            if (y < 3) {
                add_all(sub, writables(x, y + 1, lim));
            }
            for (int num : sub) {
                if (num == 0) {
                    int new_num = 10 * d;
                    while (new_num < lim) {
                        r.insert(new_num);
                        new_num *= 10;
                    }
                } else {
                    int new_num = d * pow(10, (int)log10(num) + 1) + num;
                    if (new_num < lim) {
                        r.insert(new_num);
                    }
                }
            }
            add_all(r, sub);
        }
    }
    return r;
}

vector<int> solve() {
    set<int> xs = writables(0, 0, 1000);
    vector<int> ans(201, 0);
    for (int k = 1; k <= 200; ++k) {
        int best = -1;
        int diff = 1000;
        for (int num : xs) {
            int d = abs(num - k);
            if (d < diff) {
                diff = d;
                best = num;
            }
        }
        ans[k] = best;
    }
    return ans;
}

int main()
{
    vector<int> ans = solve();
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        int k;
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
}
