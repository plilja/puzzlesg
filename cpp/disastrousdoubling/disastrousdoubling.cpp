#include <iostream>

long long M = 1e9 + 7;
long long H = 1L << 60;

int main()
{
    int n;
    scanf("%d", &n);
    long long bakteria = 1;
    bool roofReached = false,
         error = false;
    for (int i = 0; i < n; ++i) {
        long long b;
        scanf("%lld", &b);
        bakteria = 2 * bakteria - b;
        if (bakteria >= H) {
            roofReached = true;
        }
        if (roofReached) {
            bakteria = (bakteria + M) % M;
        }
        if (!roofReached && bakteria < 0) {
            error = true;
            break;
        }
    }
    if (error) {
        printf("error\n");
    } else {
        printf("%lld\n", (bakteria + M) % M);
    }
}
