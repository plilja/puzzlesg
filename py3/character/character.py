def factorial(n):
    r = 1
    for i in range(2, n + 1):
        r *= i
    return r


def binom(n, c):
    return factorial(n) // (factorial(n - c) * factorial(c))


n = int(input())
r = sum([binom(n, i) for i in range(2, n + 1)])
print(r)
