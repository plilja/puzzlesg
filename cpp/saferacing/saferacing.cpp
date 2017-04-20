#include <iostream>
#include <vector>

using namespace std;

int M = 123456789;

int main()
{
    int L, S;
    scanf("%d %d", &L, &S);
    vector<long long> v(L + 1, 0);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= L; ++i) {
       v[i] = 2 * v[i - 1]; 
       if (i - S == 1) {
           v[i] = v[i] - v[i - S];
       } else if (i - S >= 1) {
           v[i] = v[i] - v[i - S - 1];
       }
       v[i] = (v[i] + M) % M;
    }
    long long ans = 0;
    for (long long i = S; i >= 1; --i) {
        ans = (ans + v[L - i] * i) % M;
    }
    printf("%lld\n", ans);
}
