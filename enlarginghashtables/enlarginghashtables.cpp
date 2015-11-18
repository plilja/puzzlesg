#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

bool is_prime(int num)
{
    if (num < 6) {
        return num == 2 || num == 3 || num == 5;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    int lim = sqrt(num);
    for (int i = 5; i <= lim; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 2 * n + 1;; i += 2) {
            if (is_prime(i)) {
                printf("%d", i);
                break;
            }
        }
        if (!is_prime(n)) {
            printf(" (%d is not prime)", n);
        }
        puts("");
    }
}
