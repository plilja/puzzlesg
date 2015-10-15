#include <iostream>
#include <cmath>

int main()
{
    int N;
    scanf("%d", &N);
    int r = log(N) / log(2) + 1;
    printf("%d\n", r);
    int acc = 1;
    for (int i = 0; i < r; ++i) {
        printf("%d ", acc);
        acc *= 2;
    }
    puts("");
}
