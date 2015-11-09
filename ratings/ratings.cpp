#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll sum(vector<int> &reviews)
{
    ll r = 0;
    for (auto s : reviews) {
        r += s;
    }
    return r;
}

ll solve(vector<int> &reviews, int n)
{
    int score = sum(reviews);
    vector<vector<ll>> sol(n + 1, vector<ll>(score + 1, 0));
    vector<vector<ll>> less_than_or_eq(n + 1, vector<ll>(score + 1, 0));
    for (int i = 0; i <= score; ++i) {
        sol[0][i] = 1;
        less_than_or_eq[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        int review = reviews[n - i];
        for (int r = 0; r <= score; ++r) {
            for (int j = r; j <= score; ++j) {
                if (r < review) {
                    sol[i][j] += less_than_or_eq[i - 1][j - r];
                } else if (r == review) {
                    sol[i][j] += sol[i - 1][j - r];
                } else { // r > review
                    if (j - r - 1 >= 0) {
                        sol[i][j] += less_than_or_eq[i - 1][j - r - 1];
                    }
                }
                less_than_or_eq[i][j] += less_than_or_eq[i - 1][j - r];
            }
        }
    }
    return sol[n][score];
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<int> reviews(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &reviews[i]);
        }
        auto r = solve(reviews, n);
        printf("%lld\n", r);

    }
}
