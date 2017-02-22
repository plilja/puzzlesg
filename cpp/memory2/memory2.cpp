#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

const int G = 1001;

int main()
{
    vector<vector<double>> m(G, vector<double>(G + 2, 0));
    for (int i = 0; i < m[0].size(); ++i) {
        m[0][i] = 0;
    }
    for (int n = 1; n < G; ++n) {
        for (int k = n; k < m[n].size(); ++k) {
            m[n][k] = n;
        }

        for (int k = n - 1; k >= 0; --k) {
            double unknown = 2 * n - k;
            double p1 = k / unknown;
            double p2 = k / (unknown - 1);
            assert(unknown - k - 1 > 0);
            double lucky = 1 / (unknown - k - 1); // Second guess matches first guess

            double r = 1;

            // First guess is among known cards
            if (k > 0) {
                r += p1 * m[n - 1][k - 1];
            }

            // First guess is not among known cards
            double second_known = p2 * (1 + m[n - 1][k]); // Second guess is among known cards
            double second_unknown = (1 - p2) * (lucky * m[n - 1][k] + (1 - lucky) * m[n][k + 2]); // Second guess is not among known cards
            r += (1 - p1) * (second_known + second_unknown);

            m[n][k] = r;
        }
    }

    int n;
    while (1 == scanf("%d", &n)) {
        printf("%.12f\n", m[n][0]);
    }
}
