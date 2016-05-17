#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    ll sum = 0;
    ll largest = 0;
    while (n--) {
        ll t;
        scanf("%lld", &t);
        sum += t;
        largest = max(largest, t);
    }
    ll ans = max(sum, 2 * largest);
    printf("%lld\n", ans);
}
