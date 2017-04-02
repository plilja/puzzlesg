from math import *


def solve(s, h, hatches):
    for x in range(0, s + 1):
        for y in range(0, s + 1):
            leach = min(x, s - x, y, s - y)
            poss = True
            for hx, hy in hatches:
                d = sqrt((x - hx)**2 + (y - hy)**2)
                if (hx == x and hy == y) or (d > leach + 1e-9):
                    poss = False
                    break
            if poss:
                return (True, (x, y))
    return (False, None)



def read_ints():
    return tuple(map(int, input().strip().split()))


n = int(input())
for i in range(0, n):
    (s, h) = read_ints()
    hatches = []
    for j in range(0, h):
        hatches += [read_ints()]
    b, ans = solve(s, h, hatches)
    if b:
        print('%d %d' % (ans[0], ans[1]))
    else:
        print('poodle')
