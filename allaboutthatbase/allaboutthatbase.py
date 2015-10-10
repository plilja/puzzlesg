import sys

LIMIT = 2**32 - 1

def ordinal(digit):
    if digit >= '0' and digit <= '9':
        return int(digit)
    else:
        return ord(digit) - ord('a') + 10


def to_base_10(num, base):
    if base == 1:
        for c in num:
            if c != '1':
                return None
        return len(num)
    
    r = 0
    p = 1
    for d in reversed(num):
        od = ordinal(d)
        if od >= base:
            return None
        r += p * ordinal(d)
        p *= base
        if r > LIMIT:
            return None
    if r < 1:
        return None
    return r



def valid_in_base(a, op, b, r, base):
    x1 = to_base_10(a, base)
    x2 = to_base_10(b, base)
    y = to_base_10(r, base)
    if not x1 or not x2 or not y:
        return False
    if op == '+':
        return x1 + x2 == y
    elif op == '-':
        return x1 - x2 == y
    elif op == '*':
        return x1 * x2 == y
    elif op == '/':
        return x2 * y == x1
    else:
        return False
    

for inp in map(str.strip, sys.stdin.readlines()[1:]):
    a, op, b, foo, r = inp.split(' ')
    res = ''
    for base in range(1, 37):
        if valid_in_base(a, op, b, r, base):
            if base < 10:
                res += str(base)
            elif base < 36:
                res += chr(ord('a') + (base - 10))
            else: # base == 36
                res += '0'

    if res == '':
        print 'invalid'
    else:
        print res

