#include "primesieve.h"
#include <cmath>
#include <cassert>

PrimeSieve::PrimeSieve(uint n) : primes(std::vector<bool>(n / 2 + 1, true)), nr_of_primes(-1), sieve_size(n)
{
    uint n_half = n / 2 + 1;
    uint n_half_sqrt = (uint) sqrt(n_half) + 1;
    uint p, i, j;
    primes[0] = false;
    for (i = 1; i <= n_half_sqrt; ++i) {
        if (primes[i]) {
            p = i + i + 1; //p is prime
            for (j = (p * p) / 2; j <= n_half; j += p) {
                primes[j] = false;
            }
        }
    }
}

bool PrimeSieve::isPrime(uint n) const
{
    if (n <= 1) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    } else {
        return primes[n / 2];
    }
}

int PrimeSieve::numPrimes()
{
    if (nr_of_primes == -1) {
        nr_of_primes = 0;
        if (sieve_size >= 2) {
            nr_of_primes += 1;
        }

        for (bool p : primes) {
            if (p) {
                nr_of_primes++;
            }
        }
    }
    return nr_of_primes;
}

