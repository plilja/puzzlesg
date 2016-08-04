from math import *
from decimal import Decimal
import sys


def solve(i, a, b):
    m = (a + b) // 2
    r1 = m ** 3
    r2 = (m + 1) ** 3
    if r1 <= i and r2 >= i:
        if abs(r1 - i) < abs(r2 - i):
            return m
        else:
            return m + 1
    if r1 > i:
        return solve(i, a, m)
    else:
        return solve(i, m, b)


for s in sys.stdin.readlines():
    i = int(s)
    r = solve(i, 1, 10 * int(Decimal(i) ** Decimal(1/3)))
    print(r)
