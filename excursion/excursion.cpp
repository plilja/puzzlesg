#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    char kids[1000003];
    scanf("%s", kids);
    int n = strlen(kids);
    vector<int> destinations(3, 0);
    long long r = 0;
    for (int i = 0; i < n; ++i) {
        int d = (int)(kids[i] - '0');
        for (int i = d + 1; i <= 2; ++i) {
            r += destinations[i];
        }
        destinations[d]++;
    }
    printf("%lld\n", r);
}
