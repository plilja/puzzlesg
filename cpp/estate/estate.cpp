#include <iostream>

using namespace std;

int solve(int n) {
    if (n <= 1) {
        return 0;
    }
    int a = 1;
    int m = 1;
    for (int i = 2; ; ++i) {
        if (n / i - (i + 1) / 2 <= 0) {
            break;
        }
        if (i % 2 == 0) {
            if (n % i == m) {
                a++;
            }
            m++;
        }
        else {
            if (n % i == 0) {
                a++;
            }
        }
    }
    return a;
}

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        int a = solve(n);
        printf("%d\n", a);
    }
}
