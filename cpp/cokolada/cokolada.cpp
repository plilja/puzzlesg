#include <iostream>

using namespace std;

int breaks(int bar_size, int k)
{
    if (bar_size == k)
        return 0;
    if (k == 0)
        return 0;
    int half = bar_size / 2;
    if (half > k)
        return 1 + breaks(half, k);
    else
        return 1 + breaks(half, k - half);
}

int main()
{
    int k;
    scanf("%d", &k);
    int bar_size = 1;
    while (bar_size < k) {
        bar_size *= 2;
    }
    int _breaks = breaks(bar_size, k);
    printf("%d %d\n", bar_size, _breaks);
}
