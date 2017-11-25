from math import *

def solve(n):
    if n == 1:
        return (1, 1)
    else:
        level = floor(log(n, 2))
        start_level = 2**level
        place_in_level = n - start_level
        start_prev_level = start_level//2
        parent = start_prev_level + place_in_level//2
        parent_p, parent_q = solve(parent)
        if n % 2 == 0:
            return (parent_p, parent_p + parent_q)
        else:
            return (parent_p + parent_q, parent_q)


t = int(input())
for _ in range(1, t + 1):
    [k, n] = list(map(int, input().strip().split()))
    p, q = solve(n)
    print('%d %d/%d' % (k, p, q))
