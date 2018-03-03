#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int MAX = 1000;

int sign(int x) {
    if (x == 0) {
        return 0;
    } else {
        return x < 0 ? -1 : 1;
    }
}

pii w1_or_w2_is_zero(int n, int maria_x1, int maria_x2, vector<pii> &products) {
    int both_larger = 0,
        x1_equal = 0,
        x1_larger = 0,
        x2_equal = 0,
        x2_larger = 0;
    for (pii product : products) {
        int x1 = product.first,
            x2 = product.second;
        if (x1 > maria_x1 && x2 > maria_x2) {
            both_larger += 1;
            continue;
        }
        if (x1 == maria_x1) {
            x1_equal += 1;
        }
        if (x1 > maria_x1) {
            x1_larger += 1;
        }
        if (x2 == maria_x2) {
            x2_equal += 1;
        }
        if (x2 > maria_x2) {
            x2_larger += 1;
        }
    }
    int best = 1 + both_larger + min(x1_larger, x2_larger);
    int worst = 1 + both_larger + max(x1_larger + x1_equal, x2_larger + x2_equal);
    return {best, worst};
}

pii w1_or_w2_is_not_zero(int n, int maria_x1, int maria_x2, vector<pii> &products) {
    int best = n + 1,
        worst = 0;
    sort(products.begin(), products.end());
    for (int w1 = 1; w1 <= MAX; ++w1) {
        int beats = 0;
        vector<int> delta(MAX + 1, 0);
        vector<int> equal_minus(MAX + 1, 0);
        vector<int> equal_plus(MAX + 1, 0);
        int exactly_equal = 0;
        for (pii product : products) {
            int x1 = product.first,
                x2 = product.second,
                a = maria_x1*w1 - x1*w1,
                d = maria_x2 - x2;
            if (a < 0) {
                beats += 1;
            } else if (a == 0 && d < 0) {
                beats += 1;
            } else if (a == 0 && d == 0) {
                exactly_equal += 1;
            }
            if (sign(a) == sign(d) || d == 0) {
                // Value of w2 doesn't matter
                continue;
            }
            int overtake_point = abs((abs(a) + abs(d) - 1) / abs(d));
            if (overtake_point <= MAX) {
                if (a + d * overtake_point == 0) {
                    if (a < 0) {
                        equal_minus[overtake_point] += 1;
                    } else {
                        equal_plus[overtake_point] += 1;
                    }
                } else {
                    delta[overtake_point] += sign(a);
                }
            } 
        }
        for (int w2 = 1; w2 <= MAX; ++w2) {
            beats += delta[w2];
            best = min(best, beats - equal_minus[w2] + 1);
            worst = max(worst, beats + equal_plus[w2] + 1 + exactly_equal);
            beats = beats - equal_minus[w2] + equal_plus[w2];
        }
    }
    return {best, worst};
}

int main()
{
    int n;
    scanf("%d", &n);
    int maria_x1,
        maria_x2;
    scanf("%d %d", &maria_x1, &maria_x2);
    vector<pii> products;
    for (int i = 0; i < n - 1; ++i) {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        products.push_back({x1, x2});
    }
    pii a = w1_or_w2_is_zero(n, maria_x1, maria_x2, products);
    pii b = w1_or_w2_is_not_zero(n, maria_x1, maria_x2, products);
    int best = min(a.first, b.first);
    int worst = max(a.second, b.second);
    printf("%d %d\n", best, worst);
}
