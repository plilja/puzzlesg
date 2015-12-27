#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n)
{
    int r = 0;
    int lim = 2 * n;
    for (long long x = n + 1; x <= lim; ++x) {
        long long y = (long long) round(1.0 / (1.0 / n - 1.0 / x));
        if (x * y % (x + y) == 0) {
            r += 1;
        }
    }
    return r;

}

int main()
{
    vector<int> cache(10001, -1);
    int n, one;
    while (2 == scanf("%d/%d", &one, &n)) {
        int r;
        if (cache[n] != -1) {
            r = cache[n];
        } else {
            r = solve(n);
            cache[n] = r;
        }
        printf("%d\n", r);

    }

}
