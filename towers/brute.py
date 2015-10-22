import sys
from math import log

# this solution will only work for really small inputs

def solve(c, m):
    nums = []
    for i in range(0, m):
        line = sys.stdin.readline()
        powers = map(int, line.split('^'))
        num = 1
        for p in reversed(powers):
            num = p ** num
        nums += [(num, i, line)]
    nums.sort()
    print 'Case %s:' % c
    for _, _, line in nums:
        print line,


def run():
    c = 1
    while True:
        inp = sys.stdin.readline()
        if not inp:
            break
        m = int(inp)
        solve(c, m)
        c += 1


if __name__ == "__main__":
    run()
