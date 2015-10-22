import random
import sys

n = int(sys.argv[1])

for i in range(0, n):
    m = random.randint(2, 100)
    print m
    for h in range(0, m):
        num_powers = random.randint(2, 16)
        for j in range(0, num_powers):
            p = random.randint(2, 32)
            if j > 0:
                sys.stdout.write('^')
            sys.stdout.write(str(p))
        print ''
