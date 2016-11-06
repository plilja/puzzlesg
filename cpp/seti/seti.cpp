#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include "gcd.h"

using namespace std;

int modpow(int num, int exp, int mod) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return num;
    } else {
        int subRes = modpow(num, exp / 2, mod);
        int res = (subRes * subRes) % mod;
        if (exp % 2 == 1) {
            res = (res * num) % mod;
        }
        return res;
    }
}

int mod(int a, int m) {
    int r = a % m;
    if (r < 0) {
        r += m;
    }
    return r;
}

vector<int> gaussjordan(vector<vector<int>> &coeff, vector<int> y, int n, int p) {
    vector<int> x(y);
    for (int i = 0; i < n; ++i) {
        auto tmp = extendedGcd(coeff[i][i], p);
        int inv = mod(tmp.a, p);
        x[i] = mod(x[i] * inv, p);
        for (int j = i; j < n; ++j) {
            coeff[i][j] = mod(coeff[i][j] * inv, p);
        }
        if (i < n - 1) {
            for (int j = i + 1; j < n; ++j) {
                int d = coeff[j][i];
                x[j] = mod(x[j] - d * x[i], p);
                for (int h = i; h < n; ++h) {
                    coeff[j][h] = mod(coeff[j][h] - d * coeff[i][h], p);
                }
            }
        }
    }

    for (int i = n - 1; i > 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            int d = coeff[j][i];
            x[j] = mod(x[j] - d * x[i], p);
            coeff[j][i] = 0;
        }
    }
    return x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int p;
        char s[72];
        scanf("%d %s", &p, s);
        int n = strlen(s);
        vector<vector<int>> coeff(n, vector<int>(n));
        vector<int> y(n);
        for (int k = 1; k <= n; ++k) {
            for (int i = 0; i < n; ++i) {
                coeff[k - 1][i] = modpow(k, i, p);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                y[i] = 0;
            } else {
                y[i] = (int)(s[i] - 'a' + 1);
            }
        }

        auto as = gaussjordan(coeff, y, n, p);

        for (auto v : as) {
            printf("%d ", v);
        }
        printf("\n");

        // Verify result
        for (int k = 1; k <= n; ++k) {
            int fCheck = 0;
            for (int i = 0; i < n; ++i) {
                fCheck = mod(fCheck + as[i]*modpow(k, i, p), p);
            }
            if (fCheck == 0) {
                assert(s[k - 1] == '*');
            } else {
                assert(fCheck == (int)(s[k - 1] - 'a' + 1));
            }
        }
    }
}
