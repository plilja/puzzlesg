from math import *
import re

def solve(p, q):
    if p == 1 and q == 1:
        return (1, 1, 1)
    else:
        if p > q:
            p_p = p - q
            p_q = q
            x = 1
        else:
            p_p = p
            p_q = q - p
            x = 0
        p_n, p_d, p_in_level = solve(p_p, p_q)
        end_level = 2**p_d - 1
        in_level = 2 * (p_in_level - 1) + 1 + x
        n = end_level + in_level
        return n, p_d + 1, in_level

p = int(input())
for _ in range(0, p):
    s = input()
    [k, p, q] = map(int, re.match(r'(\d*) (\d*)/(\d*).*', s).groups())
    r = solve(p, q)[0]
    print(k, r)
