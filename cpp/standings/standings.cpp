#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d\n", &t);
    for (int _ = 0; _ < t; ++_) {
        int n;
        scanf("%d\n", &n);
        vector<int> teams(n);
        for (int i = 0; i < n; ++i) {
            char name[21];
            scanf("%s %d", name, &teams[i]);
        }
        sort(teams.begin(), teams.end());
        unsigned long long ans = 0;
        for (int place = 1; place <= n; ++place) {
            ans += abs(teams[place - 1] - place);
        }
        printf("%llu\n", ans);
    }
}
