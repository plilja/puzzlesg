k = int(input())
tree = {}
while True:
    xs = list(map(int, input().split()))
    b, bs = xs[0], xs[1:]
    if b == -1:
        break
    for h in bs:
        tree[h] = b

path = [k]
while path[-1] in tree:
    path += [tree[path[-1]]]

for p in path:
    print(p, end=' ')
print()
