def ints():
    return tuple(map(int, input().split()))

(n,) = ints()
platforms = [ints() for _ in range(0, n)]

r = 0
for i in range(0, n):
    ay, ax1, ax2 = platforms[i]
    left_leg = ay
    right_leg = ay
    for j in range(0, n):
        if i == j:
            continue
        by, bx1, bx2 = platforms[j]
        if by < ay and bx1 <= ax1 and ax1 < bx2:
            left_leg = min(left_leg, ay - by)
        if by < ay and bx1 < ax2 and ax2 <= bx2:
            right_leg = min(right_leg, ay - by)

    r = r + left_leg + right_leg

print(r)
