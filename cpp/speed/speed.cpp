#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double EPS = 5e-10;

int main()
{
    // Read input
    int n, t;
    scanf("%d %d", &n, &t);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int d,
            s;
        scanf("%d %d", &d, &s);
        v[i] = {d, s};
    }

    // Determine minimum possible c to consider
    double c1 = -1000;
    for (auto p : v) {
        c1 = max(c1, (double)-p.second);
    }

    // Determine maximum possible c to consider
    double total_dist = 0;
    for (auto p : v) {
        total_dist += p.first;
    }
    double avg_speed = total_dist / t;
    double c2 = avg_speed + 1000;

    // Binary search for c
    while (abs(c2 - c1) > EPS) {
        double c = (c1 + c2) / 2;
        double time = 0;
        for (auto p : v) {
            time += p.first / (p.second + c);
        }
        if (time > t) {
            c1 = c;
        } else {
            c2 = c;
        }
    }

    // Output solution
    printf("%.9lf\n", c1);
}
