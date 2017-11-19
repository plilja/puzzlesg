#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &xs[i]);
    }
    sort(xs.begin(), xs.end(), greater<int>());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 3 != 2) {
            ans += xs[i];
        }
    }
    printf("%lld\n", ans);
}
