from collections import defaultdict
from copy import copy

wildcard = 'wildcard'


def is_pattern(p):
    return p[0] == '<' and p[-1] == '>'


def solve(xs, ys):
    if len(xs) != len(ys):
        return '-'

    same = defaultdict(set)
    patterns = {}
    res = [None] * len(xs)

    # First pass, look for patterns that must be same
    for i in range(0, len(xs)):
        x = xs[i]
        y = ys[i]
        if is_pattern(x) and is_pattern(y):
            same['x_' + x] |= {'y_' + y}
            same['y_' + y] |= {'x_' + x}

    # Second pass look for patterns that can be determined
    for i in range(0, len(xs)):
        x = xs[i]
        y = ys[i]
        if not is_pattern(x) or not is_pattern(y):
            if is_pattern(x):
                if 'x_' + x in patterns and patterns['x_' + x] != y:
                    return '-'
                res[i] = y
                patterns['x_' + x] = y
            elif is_pattern(y):
                if 'y_' + y in patterns and patterns['y_' + y] != x:
                    return '-'
                res[i] = x
                patterns['y_' + y] = x
            else:
                # none are patterns
                if x != y:
                    return '-'
                else:
                    res[i] = x
    
    # Follow "same-pointers" to propagate determined patterns to neighbours
    def propagate_same(pattern, value, visited):
        if pattern in visited:
            return True
        else:
            visited.add(pattern)
            if pattern in patterns:
                if patterns[pattern] != value:
                    return False
            else:
                patterns[pattern] = value
            res = True
            for p in same[pattern]:
                res = res and propagate_same(p, value, visited)
            return res

    for k, v in copy(patterns).items():
        if not propagate_same(k, v, set()):
            return '-'

    # Third pass, store determined "same-patterns" in result
    for i in range(0, len(xs)):
        x = xs[i]
        y = ys[i]
        if not res[i]:
            assert(is_pattern(x) and is_pattern(y))
            if 'x_' + x in patterns:
                r = patterns['x_' + x]
                assert('y_' + y in patterns and r == patterns['y_' + y])
                res[i] = r
            else:
                res[i] = wildcard

    return ' '.join(res)


n = int(input())
for _ in range(0, n):
    xs = input().strip().split()
    ys = input().strip().split()
    print(solve(xs, ys))
