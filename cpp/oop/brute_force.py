import sys

[n, q] = list(map(int, sys.stdin.readline().split()))


words = []
for i in range(0, n):
    words += [sys.stdin.readline().strip()]

patterns = []
for i in range(0, q):
    patterns += [sys.stdin.readline().strip()]

for p in patterns:
    count = 0
    for w in words:
        [a,b] = p.split('*')
        if w.startswith(a) and w.endswith(b) and len(a+b) <= len(w):
            count+= 1
    print(count)


