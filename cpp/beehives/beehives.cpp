#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    double d;
    int n;
    while (true) {
        scanf("%lf %d", &d, &n);
        if (d == 0.0 && n == 0) {
            break;
        }
        vector<pair<double, double>> hives;
        for (int i = 0; i < n; ++i) {
            double a, b;
            scanf("%lf %lf", &a, &b);
            hives.push_back({a, b});
        }
        int sweet = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    auto h1 = hives[i];
                    auto h2 = hives[j];
                    if (sqrt(pow(h1.first - h2.first, 2) + pow(h1.second - h2.second, 2)) < d + 1e-9) {
                        sweet--;
                        break;
                    }
                }
            }
        }
        printf("%d sour, %d sweet\n", n - sweet, sweet);
    }
}
