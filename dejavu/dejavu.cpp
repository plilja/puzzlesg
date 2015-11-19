#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> point;

int main()
{
    int n;
    scanf("%d", &n);
    vector<point> points(n);
    vector<ll> points_per_x(100001, 0);
    vector<ll> points_per_y(100001, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        points_per_x[x] += 1;
        points_per_y[y] += 1;
        points[i] = {x, y};
    }
    ll r = 0;
    for (auto &p : points) {
        r += (points_per_x[p.first] - 1) * (points_per_y[p.second] - 1);
    }
    printf("%lld\n", r);
}
