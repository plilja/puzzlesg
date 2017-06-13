#include <iostream>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);
    int lim = sqrt(n);
    int smallest_prime_factor = n;
    for (int i = 2; i <= lim; ++i) {
        if (n % i == 0) {
            smallest_prime_factor = i;
            break;
        }
    }
    int counter = n - n / smallest_prime_factor;
    printf("%d\n", counter);
}
