import sys

def solve(n):
    if n > 25:
        return 0
    r = [i for i in range(1, 10)]
    for i in range(2, n + 1):
        tmp = []
        for j in r:
            for k in range(0, 10):
                cand = 10 * j + k
                if cand % i == 0:
                    tmp += [cand]
        r = tmp
    return len(r)


for s in sys.stdin.readlines():
    n = int(s)
    print(solve(n))
