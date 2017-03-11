import sys


def solve(s):
    for i in range(len(s) - 1, 0, -1):
        poss = True
        for j in range(0, len(s) - i + 1):
            sub = s[j:j+i]
            if s.find(sub) == j and s.rfind(sub) == j:
                poss = False
                break
        if poss:
            return i
    return 0


for line in sys.stdin.readlines():
    print(solve(line.strip()))
