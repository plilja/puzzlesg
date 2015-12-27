#include <iostream>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        double globalTMax = -1;
        int highestTorqueGear = 0;
        for (int j = 0; j  < n; ++j) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            // dT(R) = -2*aR + b, is equal to 0, when R = b/2a
            double rMax = b / (2.0 * a);
            double tMax = -a * rMax * rMax + b * rMax + c;
            if (globalTMax < tMax) {
                highestTorqueGear = j + 1;
                globalTMax = tMax;
            }
        }
        printf("%d\n", highestTorqueGear);
    }
}
