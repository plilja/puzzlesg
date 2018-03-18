#include <iostream>
#include <vector>

using namespace std;

const int W = 10000010 + 150;

vector<bool> init_sieve() {
    vector<bool> sieve(W, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i < W; ++i) {
       if (sieve[i]) {
           int j = 2 * i;
           while (j < W) {
               sieve[j] = false;
               j += i;
           }
       }
    }
    return sieve;
}

vector<vector<vector<int>>> precalc_solutions() {
    vector<vector<vector<int>>> sol(151, vector<vector<int>>(151, vector<int>(152, -1)));
    auto sieve = init_sieve();
    int num_primes = 0;
    // In 1 - 150 range
    for (int i = 1; i <= 150; ++i) {
        for (int M = 0; M <= 150; ++M) {
            int num_happy = 0;
            for (int j = i; j < i + 150; ++j) {
                if (j <= M || sieve[j]) {
                    num_happy++;
                }
                int K = j - i + 1;
                int L = num_happy;
                sol[K][L][M] = i;
            }
        }
    }
    // Outside 1 - 150 range
    for (int i = 151; i <= 10000000; ++i) {
        if (sieve[i]) {
            int num_happy = 0;
            for (int j = i; j < i + 150; ++j) {
                if (sieve[j]) {
                    num_happy++;
                }
                int K = j - i + 1;
                int L = num_happy;
                sol[K][L][151] = i;
            }
        }
    }
    return sol;
}

int main() {
    int FEW_PRIMES = 8421253;
    auto solutions = precalc_solutions();
    int q;
    scanf("%d", &q);
    while (q--) {
        int K, L, M;
        scanf("%d %d %d", &K, &L, &M);
        int r = -1;
        if (L == 0) {
            r = FEW_PRIMES;
        }
        if (r == -1) {
            r = solutions[K][L][M];
        }
        if (r == -1) {
            r = solutions[K][L][151]; // Look for start outside 1 - 150 range
        }
        printf("%d\n", r);
    }
}
