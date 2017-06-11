from collections import Counter

n = int(input())

frosh = []
for i in range(0, n):
    f = map(int, input().split())
    frosh += [tuple(sorted(f))]

c = Counter(frosh)
r = 0
prev = None
for _, n in c.most_common():
    if prev and n != prev:
        break
    r += n
    prev = n
    
print(r)
