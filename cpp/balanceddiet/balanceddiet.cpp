#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int INF = 10e6;

pii helper(vector<int> &cans, int n, int i, int curr, int rem) {
    if (curr >= rem) {
        return {curr, rem};
    } else if (i >= n) {
        return {INF, 0};
    } else {
        int c = cans[i];
        auto t1 = helper(cans, n, i + 1, curr, rem);
        auto t2 = helper(cans, n, i + 1, curr + c, rem - c);
        if (t1.first - t1.second < t2.first - t2.second) {
            return t1;
        } else {
            return t2;
        }
    }
}

pii solve(vector<int> &cans, int n) {
    int total = 0;
    for (auto c : cans) {
        total += c;
    }
    return helper(cans, n, 0, 0, total);
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<int> cans(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cans[i]);
        }
        auto r = solve(cans, n);
        printf("%d %d\n", r.first, r.second);
    }
}
