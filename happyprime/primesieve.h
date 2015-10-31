#pragma once

#include <vector>

typedef unsigned int uint;

/*
    Provides a data structure holding information about
    which numbers are prime and which aren't below a given 
    limit. 
*/
class PrimeSieve
{
private:
    std::vector<bool> primes;
    int nr_of_primes;
    uint sieve_size;
public:
    /*
     * Construct a prime sieve of size n using
     * the sieve of eratosthenes algorithm.
     *
     * Parameters:
     * n : The size of the sieve (inclusive)
     */
    PrimeSieve(uint n);

    /*
     * The number of primes in the sieve.
     */
    int numPrimes();

    /*
     * Tells if n is a prime number.
     *
     * Running time O(1)
     */
    bool isPrime(uint n) const;
};
