#include <iostream>
#include <cmath>
#include <algorithm>

double EPS = 10e-9;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        int score = 0;
        for (int j = 0; j < n; ++j) {
            int x, y;
            scanf("%d %d", &x, &y);
            double dist_from_centre = sqrt(x * x + y * y);
            score += std::max(0, 10 - (int)(dist_from_centre - EPS)/ 20);
        }
        printf("%d\n", score);

    }
}
