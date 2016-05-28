import sys
from math import *

line = sys.stdin.readline

[L, W, n, r] = map(int, line().split())
EPS = 1e-9

cranes = []
for i in range(0, n):
    [x, y] = map(int, line().split())
    cranes += [(2*x, 2*y)] # Double lenghts, that way we can forget about floating precision

def solve(i, walls, cache = {}):
    if len(walls) == 0:
        return 0
    if i == n:
        return n + 1
    if (i, walls) in cache:
        return cache[(i, walls)]

    (cx, cy) = cranes[i]
    walls_ = []
    for (x, y) in walls:
        if sqrt((cx - x)**2 + (cy - y)**2) > 2*r + EPS:
            walls_ += [(x, y)]
    ans = 1 + solve(i + 1, tuple(walls_), cache)
    ans = min(ans, solve(i + 1, walls, cache))
    cache[(i, walls)] = ans
    return ans


ans = solve(0, ((-L, 0), (L, 0), (0, -W), (0, W)))

if ans <= n:
    print(ans)
else:
    print('Impossible')
