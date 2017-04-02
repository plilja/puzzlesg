import sys

EPS = 1e-10

def solve(x, cache):
    if abs(x) < EPS:
        return True
    else:
        for i in [0, 2]:
            y = 3 * (x - i * 3**-1)
            key = '%.10f' % y
            if key in cache:
                return cache[key]
            if y >= -EPS and y <= 1 + EPS:
                cache[key] = True
                b = solve(y, cache)
                cache[key] = b
                if b:
                    return True
        return False


for s in map(str.strip, sys.stdin.readlines()):
    if s == 'END':
        break
    x = float(s)
    if solve(x, {}):
        print('MEMBER')
    else:
        print('NON-MEMBER')
