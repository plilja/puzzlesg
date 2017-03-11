#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Stone {
    int bottom;
    int top;
    double price;
};

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<vector<Stone>> stones(1001, vector<Stone>());
        for (int i = 0; i < n; ++i) {
            int a, b, h;
            scanf("%d %d %d", &a, &b, &h);
            double area = a * h + (b - a) *h / 2.0;
            double price = 2 * area / 100.0;
            stones[b].push_back(Stone({b, a, price}));
            stones[a].push_back(Stone({a, b, price}));
        }
        int walkway, gazebo;
        scanf("%d %d", &walkway, &gazebo);
        vector<double> m(1001, numeric_limits<double>::infinity());
        m[walkway] = 0;
        for (int i = 0; i < 1000; ++i) {
            for (int width = 1; width <= 1000; ++width) {
                double price = m[width];
                for (auto &stone : stones[width]) {
                    m[stone.top] = min(m[stone.top], price + stone.price);
                }
            }
        }
        printf("%.2f\n", m[gazebo]);
    }
}
