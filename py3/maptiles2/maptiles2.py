quadkey = input().strip()
level = len(quadkey)
x, y = 0, 0
for i in range(0, level):
    c = int(quadkey[i])
    if c % 2 == 1:
        x += 2**(level - i - 1)
    if c > 1:
        y += 2**(level - i - 1)
print(level, x, y)
