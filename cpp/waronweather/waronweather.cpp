#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

const double RAD = 4e4 / (2 * M_PI);

struct Point {
    double x, y, z;
};

int main()
{
    while (true) {
        int k, m;
        scanf("%d %d", &k, &m);
        if (k == 0 && m == 0) {
            break;
        }
        vector<Point> satellites(k);
        for (int i = 0; i < k; ++i) {
            scanf("%lf %lf %lf", &satellites[i].x, &satellites[i].y, &satellites[i].z);
        }
        vector<Point> target(m);
        for (int i = 0; i < m; ++i) {
            scanf("%lf %lf %lf", &target[i].x, &target[i].y, &target[i].z);
        }
        vector<bool> hit(m, false);
        for (int i = 0; i < k; ++i) {
            auto &s = satellites[i];
            double satD = sqrt(s.x*s.x + s.y*s.y + s.z*s.z);
            double maxD = sqrt(satD*satD - RAD*RAD);
            for (int j = 0; j < m; ++j) {
                auto &t = target[j];
                double d = sqrt(pow(t.x - s.x, 2) + pow(t.y - s.y, 2) + pow(t.z - s.z, 2));
                if (d < maxD + 1e-8) {
                    hit[j] = true;
                }
            }
        }
        int r = 0;
        for (auto b : hit) {
            if (b) {
                r++;
            }
        }
        printf("%d\n", r);
    }
}
