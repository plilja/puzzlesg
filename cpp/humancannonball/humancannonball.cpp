#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "dijkstra.h"

using namespace std;

typedef pair<double, double> point;

double dist(point a, point b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double time_from_cannon(point cannon_point, point target) {
    double straight_dist = dist(cannon_point, target);
    return min(straight_dist / 5, abs(straight_dist - 50) / 5 + 2);
}

double solve(vector<point> &c, int n, point current, point target) {
    vector<pair<pair<int, int>, double>> edges;
    int sn = n;
    int tn = sn + 1;
    edges.push_back({{sn, tn}, dist(current, target) / 5});
    for (int i = 0; i < n; ++i) {
        edges.push_back({{sn, i}, dist(current, c[i]) / 5});
    }
    for (int i = 0; i < n; ++i) {
        edges.push_back({{i, tn}, time_from_cannon(c[i], target)});
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                edges.push_back({{i, j}, time_from_cannon(c[i], c[j])});
            }
        }
    }
    Dijkstra dj(n + 2, edges, sn);
    return dj.distance(tn);
}

int main() {
    double cx, cy, tx, ty;
    int n;
    cin >> cx >> cy >> tx >> ty >> n;
    vector<point> c;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        c.push_back({x, y});
    }
    double r = solve(c, n, {cx, cy}, {tx, ty});
    printf("%.6f\n", r);
}
