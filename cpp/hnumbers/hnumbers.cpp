#include <iostream>
#include <vector>
#include <cassert>
#include "factorization.h"
#include "combinatorics.h"

using namespace std;

int main()
{
    // Prepare answers by computing "H-primesieve"
    int n = 1000001;
    vector<vector<int>> primes(n + 1, vector<int>());
    for (int i = 4 + 1; i <= n; i += 4) {
        if (primes[i].size() == 0) {
            for (int j = 4 + 1; j * i <= n; j += 4) {
                int tmp = i * j;
                while ((tmp % i) == 0) {
                    tmp /= i;
                    primes[i * j].push_back(i);
                }
            }
        }
    }

    // Count and store all primes
    int count = 0;
    vector<int> primecount(n + 1, 0);
    for (int i = 4 + 1; i <= n; i += 4) {
        if (primes[i].size() == 2) {
            count += 1;
        }
        if (primes[i].size() > 2 && primes[i].size() % 2 == 0) {
            for (auto pick : waysToPick(primes[i], 2)) {
                if (pick[0] * pick[1] == i) {
                    count += 1;
                    break;
                }
            }
        }
        primecount[i] = count;
    }

    // Read input and output answers
    int input;
    while (1 == scanf("%d", &input)) {
        if (input == 0) {
            break;
        }
        printf("%d %d\n", input, primecount[input]);
    }
}

