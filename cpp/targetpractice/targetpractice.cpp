#include <iostream>
#include <vector>

using namespace std;

bool in_line(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) == 0;
}

/* 
 * Test if solution is possible if a and b are in line.
 *
 * Return true or pair of false and first point not in line with a and b.
 */
pair<bool, int> test_assumption(int n, vector<int> &x, vector<int> &y, int a, int b) {
    int c = -1, d = -1;
    for (int i = 0; i < n; ++i) {
        if (i != a && i != b && !in_line(x[a], y[a], x[b], y[b], x[i], y[i])) {
            if (c == -1) {
                c = i;
            } else if (d == -1) {
                d = i;
            } else if (!in_line(x[c], y[c], x[d], y[d], x[i], y[i])) {
                return {false, c};
            }
        }
    }
    return {true, -1};
}

bool solve(int n, vector<int> &x, vector<int> &y) {
    if (n <= 4) {
        return true;
    }
    auto p1 = test_assumption(n, x, y, 0, 1);
    if (p1.first) {
        return true;
    }
    auto p2 = test_assumption(n, x, y, 0, p1.second);
    if (p2.first) {
        return true;
    }
    auto p3 = test_assumption(n, x, y, 1, p1.second);
    return p3.first;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    if (solve(n, x, y)) {
        puts("success");
    } else {
        puts("failure");
    }
}
