import random
import sys

t = int(sys.argv[1])
n = int(sys.argv[2])

print t
for i in range(0, t):
    print n, 
    one_is_positive = False
    for j in range(0, n):
        jury = random.randint(0, 10)
        if jury > 0:
            one_is_positive = True
        if j == n - 1 and not one_is_positive:
            print 1,
        else:
            print jury,
    print ''

