from math import *

EPS = 1e-9

def ints():
    return list(map(int, input().strip().split()))

[n, m, k] = ints()

plots = ints()
round_houses = ints()
square_houses = ints()

house_radiuses = round_houses[::]

# convert square houses to radiuses
for side in square_houses:
    r = sqrt(2 * (side/2)**2)
    house_radiuses += [r]

plots.sort()
house_radiuses.sort()

i = 0
j = 0
ans = 0
while i < len(plots) and j < len(house_radiuses):
    p = plots[i]
    r = house_radiuses[j]
    if r < p - EPS:
        ans += 1
        i += 1
        j += 1
    else:
        i += 1

print(ans)
