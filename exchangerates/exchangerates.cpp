#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double COMMISSION = 0.97;

double to_cents(double d)
{
    return floor(100.0 * d) / 100.0;
}

int main()
{
    while (true) {
        int d;
        scanf("%d", &d);
        if (d == 0) {
            break;
        }
        double cd = 1000;
        double usd = 0;
        for (int i = 0; i < d; ++i) {
            double r;
            scanf("%lf", &r);
            double new_cd = max(cd, to_cents(COMMISSION * usd * r));
            double new_usd = max(usd, to_cents(COMMISSION * cd * (1 / r)));
            cd = new_cd;
            usd = new_usd;
        }
        printf("%.2lf\n", cd);
    }
}
