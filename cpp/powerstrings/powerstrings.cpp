#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "factorization.h"

using namespace std;

int main()
{
    char str[2000005];
    while (1 == scanf("%s", str)) {
        if (str[0] == '.') {
            break;
        }
        int n = strlen(str);
        int best = n;
        if (n == 1) {
            puts("1");
            continue;
        }
        vector<int> ds = divisors(n);
        map<int, bool> tried;
        for (int k = ds.size() - 2; k >= 0; --k) {
            int d = ds[k];
            bool poss = true;
            for (auto kv : tried) {
                if (kv.first % d == 0) {
                    poss = poss && kv.second;
                }
            }
            int a = n / d;
            for (int i = 0; i < d && poss; ++i) {
                char c1 = str[i];
                for (int j = 1; j < a && poss; ++j) {
                    char ci = str[j * d + i];
                    poss = c1 == ci;
                }
            }
            if (poss) {
                best = d;
            }
            tried[d] = poss;
        }
        printf("%d\n", n / best);
    }
}
