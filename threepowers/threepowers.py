import sys

for n in map(int, sys.stdin.readlines()):
    if n == 0:
        break

    n -= 1 # zero indexed
    i = 1
    res = []
    while n > 0:
        b = n & 1
        if b != 0:
            res += [str(i)]
        n >>= 1
        i *= 3
    res += []
    if res:
        print "{ %s }" % ", ".join(res)
    else:
        print "{ }"
