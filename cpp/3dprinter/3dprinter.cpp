#include <iostream>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);
    int a = (int) ceil(log(n) / log(2)) + 1;
    printf("%d\n", a);
}
