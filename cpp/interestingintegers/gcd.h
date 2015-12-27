#pragma once

#include <cmath>

template <typename T>
T gcd(T a, T b)
{
    while (b != 0) {
        T t  = b;
        b = a % b;
        a = t;
    }
    return a;
}

template <typename T>
T lcm(T a, T b)
{
    return std::abs(a * b) / gcd(a, b);
}


template <typename T>
struct ExtGcdResult {
    T a;
    T b;
    T gcd;
};

template <typename T>
ExtGcdResult<T> extendedGcd(T a, T b)
{
    T s = 0;
    T t = 1;
    T r = b;
    T old_s = 1;
    T old_t = 0;
    T old_r = a;
    while (r != 0) {
        T q = old_r / r;

        T tmp1 = r;
        r = old_r - q * r;
        old_r = tmp1;

        T tmp2 = s;
        s = old_s - q * s;
        old_s = tmp2;

        T tmp3 = t;
        t = old_t - q * t;
        old_t = tmp3;
    }
    return ExtGcdResult<T>({old_s, old_t, old_r});
}

