#include <iostream>
#include <vector>
#include "pointinpolygon.h"

using namespace std;

int main()
{
    int xa, ya, xb, yb, xc, yc;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);

    // Calculate area
    double area = abs(xa*(yb - yc) + xb*(yc - ya) + xc*(ya - yb)) / 2.0;
    printf("%.1lf\n", area);

    // Calculate trees in area
    vector<pair<int, int>> triangle;
    triangle.push_back({xa, ya});
    triangle.push_back({xb, yb});
    triangle.push_back({xc, yc});
    int n;
    scanf("%d", &n);
    int r = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        auto t = pointinpoly({x, y}, triangle);
        if (t == IN || t == ON) {
            r++;
        }
    }
    printf("%d\n", r);
}
