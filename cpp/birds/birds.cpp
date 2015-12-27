#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int POLE_DIST = 6;

int main()
{
    int L, D, N;
    scanf("%d %d %d", &L, &D, &N);
    vector<int> birds(N + 2);
    birds[0] = POLE_DIST - D;
    birds[N + 1] = L - POLE_DIST + D;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &birds[i]);
    }
    sort(birds.begin(), birds.end());
    int r = 0;
    for (int i = 0; i < N + 1; ++i) {
        int a = birds[i] + D;
        int b = birds[i + 1] - D;
        bool in_interwall = a >= 0 && b <= L;
        if (in_interwall && b - a >= 0) {
            r += (b - a) / D + 1;
        }
    }
    printf("%d\n", r);
}
