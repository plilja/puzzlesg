#pragma once

#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

/**
 * Returns the prime factors of a positive number greater than 1 
 * in increasing order. 
 *
 * If one factor exists multiple times in the factorization it will 
 * exists multiple times in the result.
 *
 * The prime factors will be returned in increasing order.
 *
 * Example: factorization(12) = [2, 2, 3]
 */
template <typename T>
std::vector<T> factorization(T x)
{
    assert(x > 1);
    std::vector<T> ans;
    while (x % 2 == 0) {
        ans.push_back(2);
        x /= 2;
    }
    T upper_lim = sqrt(x);
    for (int i = 3; i <= upper_lim; i += 2) {
        bool redefine_limit = false;
        while (x % i == 0) {
            ans.push_back(i);
            x /= i;
            redefine_limit = true;
        }
        if (redefine_limit) {
            upper_lim = sqrt(x);
        }

    }
    if (x > 1) {
        ans.push_back(x);
    }
    
    return ans;
}

/**
 * Returns the distinct prime factors of a positive number in increasing order.
 *
 * Example: prime_factors(12) = [2, 3]
 */
template <typename T>
std::vector<T> prime_factors(T x) 
{
    auto f = factorization(x);
    std::vector<T> ans;
    T prev = x + 1;
    for (auto &p : f) {
        if (p != prev) {
            ans.push_back(p);
        }
        prev = p;
    }
    return ans;
}

/**
 * Returns all the divisors of a positive number in increasing order.
 *
 * Returns divisors regardless if they are prime factors or not.
 *
 * Example: divsors(12) == [1,2,3,4,6,12]
 */
template <typename T>
std::vector<T> divisors(T x)
{
    std::vector<T> pf = prime_factors(x);
    std::vector<T> ans;
    ans.push_back(1);
    for (auto &p : pf) {
        std::vector<T> powers;
        int n = 0;
        T acc = 1;
        while (x % (acc * p) == 0) {
            acc *= p;
            n++;
            powers.push_back(acc);
        }
        int curr_size = ans.size();
        for (int i = 0; i < curr_size; ++i) {
            for (auto &power : powers) {
                ans.push_back(ans[i] * power);
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}
