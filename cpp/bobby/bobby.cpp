#include <iostream>
#include <cmath>

double EPS = 10e-09;

double fact(int n)
{
    double r = 1.0;
    for (int i = 2; i <= n; ++i) {
        r *= i;
    }
    return r;
}

double binom(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int R, S, X, Y, W;
        scanf("%d %d %d %d %d", &R, &S, &X, &Y, &W);
        double p = (S - R + 1.0) / S;
        double actOdds = 0;
        double betOdds = 1.0 / W;
        for (int xp = X; xp <= Y && actOdds < betOdds + EPS; ++xp) {
            actOdds += binom(Y, xp) * pow(p, xp) * pow(1 - p, Y - xp);
        }
        if (actOdds > betOdds + EPS) {
            puts("yes");
        } else {
            puts("no");
        }
    }
}
