from math import *

def nums():
    return list(map(float, input().strip().split()))

m, n, r = nums()
ax, ay, bx, by = nums()

ans = float('inf')
for y in range(0, int(min(ay, by)) + 1):
    y_dist = (abs(ay - y) + abs(by - y)) * r / n
    circ = 2 * pi * y * (r / n)
    x_dist = abs(ax - bx) * circ / (2 * m)
    ans = min(ans, y_dist + x_dist)
print('%.14f' % ans)
