#include <iostream>
#include <set>

using namespace std;

int solve(set<int> &damaged, set<int> &reserves) {
    if (damaged.empty() || reserves.empty()) {
        return damaged.size();
    }
    int r = *reserves.begin();
    reserves.erase(r);

    // Do not use reserve kayak r
    int ans = solve(damaged, reserves);

    // Use reserve kayak r to help team on the left
    if (damaged.count(r - 1) > 0) {
        damaged.erase(r - 1);
        ans = min(ans, solve(damaged, reserves));
        damaged.insert(r - 1);
    }

    // Use reserve kayak r to help team on the right
    if (damaged.count(r + 1) > 0) {
        damaged.erase(r + 1);
        ans = min(ans, solve(damaged, reserves));
        damaged.insert(r + 1);
    }

    reserves.insert(r);
    return ans;
}

int main()
{
    int n, s, r;
    scanf("%d %d %d", &n, &s, &r);
    set<int> damaged;
    for (int i = 0; i < s; ++i) {
        int d;
        scanf("%d", &d);
        damaged.insert(d);
    }
    set<int> reserves;
    for (int i = 0; i < r; ++i) {
        int r;
        scanf("%d", &r);
        reserves.insert(r);
    }
    int ans = solve(damaged, reserves);
    printf("%d\n", ans);
}
