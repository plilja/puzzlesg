#include <iostream>
#include <cmath>

int main()
{
    while (true) {
        int D, V;
        scanf("%d %d", &D, &V);
        if (D == 0 && V == 0)
            break;
        double Dp = D / 2.0;
        double t = V  - 2 * pow(Dp, 3) * M_PI + (2 / 3.0) * pow(Dp, 3) * M_PI;
        double dp = pow(- 3 * t / (M_PI * 4), 1 / 3.0);
        printf("%.9lf\n", 2 * dp);
    }
}
