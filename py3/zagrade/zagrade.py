import sys

def f(inp):
    def g(inp):
        i = inp.find('(')
        j = i if i != -1 else -1
        v = -1 if i != -1 else 0

        while v != 0:
            j += 1
            if inp[j] == '(':
                v -= 1
            elif inp[j] == ')':
                v += 1

        if i != -1 and j > i:
            r1 = set()
            for s in g(inp[i + 1:j]):
                r1 |= {inp[:i + 1] + s + ')'}
                r1 |= {inp[:i] + s}
            r = set()
            for s1 in g(inp[j + 1:]):
                for s2 in r1:
                    r |= {s2 + s1}
            return r
        else:
            return {inp}

    return sorted(g(inp) - {inp})

for s in f(sys.stdin.readline().strip()):
    print(s)
