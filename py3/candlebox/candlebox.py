from math import *

def solve(d, r, t):
    for rita_age in range(3 + d, 1000):
        theo_age = rita_age - d
        rita_candles = round(((4 + rita_age)/2) * (rita_age - 4 + 1))
        theo_candles = round(((3 + theo_age)/2) * (theo_age - 3 + 1))
        if rita_candles + theo_candles == t + r:
            return r - rita_candles
    raise ValueError('No solution found')


d = int(input())
r = int(input())
t = int(input())
print(solve(d, r, t))
