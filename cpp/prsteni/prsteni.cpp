#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int prev_r, 
        a = 1,
        b = 1;
    scanf("%d", &prev_r);
    for (int i = 0; i < n - 1; ++i) {
        int r;
        scanf("%d", &r);
        int g = gcd(a * prev_r, b * r);
        a = a * prev_r / g;
        b = b * r / g;
        printf("%d/%d\n", a, b);
        prev_r = r;
    }
}
