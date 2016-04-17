import sys
from collections import defaultdict

def readln():
    return sys.stdin.readline().strip()

t = int(readln())

for i in range(0, t):
    n = int(readln())
    en_to_pizza = defaultdict(set)
    it_to_pizza = defaultdict(set)
    for j in range(0, n):
        pizza = readln()
        for it in readln().split(' ')[1:]:
            it_to_pizza[it] |= {pizza}
        for en in readln().split(' ')[1:]:
            en_to_pizza[en] |= {pizza}

    for it in sorted(it_to_pizza):
        for en in sorted(en_to_pizza):
            if it_to_pizza[it] == en_to_pizza[en]:
                print('(%s, %s)' % (it, en))
    
    if i < t - 1:
        print()
