import sys
from queue import PriorityQueue
from collections import defaultdict

line = sys.stdin.readline

cases = int(line())

for i in range(1, cases + 1):
    [n, t] = map(int, line().split())
    e = int(line())
    es = defaultdict(PriorityQueue)
    cs = defaultdict(int)

    for j in range(0, e):
        [h, c] = map(int, line().split())
        es[h].put(-c)
        cs[h] += 1

    poss = True
    ans = []
    for j in range(1, n + 1):
        if j == t:
            ans += [0]
        else:
            a = 0
            c = 0
            while c < cs[j] and not es[j].empty():
                k = -es[j].get()
                c += k
                a += 1
            if c < cs[j]:
                poss = False
                ans += [-1]
            else:
                ans += [a]

    print('Case #%d: ' % i, end='')
    if poss:
        for j in ans:
            print(j, end=' ')
        print()
    else:
        print('IMPOSSIBLE')
