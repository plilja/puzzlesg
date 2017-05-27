#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    double e = exp(1);
    double r;
    if (n > 100) {
        r = 1 - 1 / e;
    } else {
        double fact = 1;
        for (int i = 2; i <= n; ++i) {
            fact *= i;
        }
        double derangements = round(fact / e);
        r = 1 - derangements / fact;
    }
    printf("%.8lf\n", r);
}
