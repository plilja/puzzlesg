#include "factorization.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 4) {
            break;
        }
        int t = n;
        int r = 1;
        while (true) {
            auto v = factorization(t);
            if (v.size() == 1) {
                break;
            }
            t = 0;
            for (auto p : v) {
                t += p;
            }
            r++;
        }
        printf("%d %d\n", t, r);
    }
}
