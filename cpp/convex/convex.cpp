#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int R = 2*1e7;

int gcd(int a, int b) {
    while (b != 0) {
        int t  = b;
        b = a % b;
        a = t;
    }
    return a;
}

void printHalfMoon(int maxPoints, int startX, int startY, int a, int b, vector<pair<double, pair<int, int>>> &points) {

    int i = 0;
    int x = startX;
    int y = startY;
    while (i < maxPoints) {
        x += points[i].second.first * a;
        y += points[i].second.second * b;
        printf("%d %d\n", x, y);
        i++;
    }
    assert(x >= 0);
    assert(y >= 0);
    assert(x <= 4*1e7);
    assert(y <= 4*1e7);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, pair<int, int>>> points_by_dist;
    vector<pair<double, pair<int, int>>> points_by_slope;
    for (int y = 1; y < 1000; ++y) {
        for (int x = 1; x < 1000; ++x) {
            if (gcd(x, y) == 1) {
                int sqDist = x*x + y*y;
                points_by_dist.push_back({sqDist, {x, y}});
            }
        }
    }
    int c1 = n / 4;
    int c2 = n - 3 * c1;
    assert(points_by_dist.size() >= n);
    sort(points_by_dist.begin(), points_by_dist.end());
    for (int i = 0; i < c2; ++i) {
        int x = points_by_dist[i].second.first;
        int y = points_by_dist[i].second.second;
        double slope = ((double) y) / x;
        points_by_slope.push_back({slope, {x, y}});
    }
    sort(points_by_slope.begin(), points_by_slope.end());

    printHalfMoon(c2, R, 0, 1, 1, points_by_slope);
    printHalfMoon(c1, R, 0, -1, 1, points_by_slope);
    printHalfMoon(c1, R, 2*R, 1, -1, points_by_slope);
    printHalfMoon(c1, R, 2*R, -1, -1, points_by_slope);
}
