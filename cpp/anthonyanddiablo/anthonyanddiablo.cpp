#include <iostream>
#include <cmath>

double EPS = 1e-9;

int main()
{
    double a, n;
    scanf("%lf %lf" , &a, &n);
    double diameter = n / M_PI;
    double maxArea = M_PI * pow(diameter/2, 2);
    if (maxArea + EPS > a) {
        puts("Diablo is happy!");
    } else {
        puts("Need more materials!");
    }
}
