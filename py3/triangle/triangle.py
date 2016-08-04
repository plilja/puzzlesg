from sys import *
from decimal import *

i = 1
for n in map(int, stdin.readlines()):
    triangles = 3**n
    circumference = Decimal(3) / Decimal(2**n)
    total = triangles * circumference
    digits = int(total.log10()) + 1
    print('Case %d: %d' % (i, digits))
    i += 1
