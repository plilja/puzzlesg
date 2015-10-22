import sys
from math import *

def is_prime(num):
    if num < 6:
        return num == 2 or num == 3 or num == 5
    if not num % 2 or not num % 3:
        return False
    for i in range(5, int(sqrt(num)) + 1, 6):
        if num % i == 0 or num % (i + 2) == 0:
            return False
    return True


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


for inp in map(str.strip, sys.stdin.readlines()[1:]):
    n = 0
    d = 0
    for b in [2, 8, 10, 16]:
        try:
            h = int(inp, b)
            n += 1
            if is_prime(h):
                d += 1
        except ValueError:
            pass

    g = gcd(n ,d)
    print '%d/%d' % (d/g, n/g)



