from collections import defaultdict


def piece1():
    return [
        [[1],
         [1],
         [1],
         [1]],
        [[1, 1, 1, 1]]
    ]


def piece2():
    return [[[1, 1],
             [1, 1]]]


def piece3():
    return [
        [[0, 1, 1],
         [1, 1, 0]],
        [[1, 0],
         [1, 1],
         [0, 1]]
    ]


def piece4():
    return [
        [[1, 1, 0],
         [0, 1, 1]],
        [[0, 1],
         [1, 1],
         [1, 0]]
    ]


def piece5():
    return [
        [[0, 1, 0],
         [1, 1, 1]],
        [[0, 1],
         [1, 1],
         [0, 1]],
        [[1, 0],
         [1, 1],
         [1, 0]],
        [[1, 1, 1],
         [0, 1, 0]]
    ]


def piece6():
    return [
        [[0, 0, 1],
         [1, 1, 1]],
        [[1, 1],
         [0, 1],
         [0, 1]],
        [[1, 1, 1],
         [1, 0, 0]],
        [[1, 0],
         [1, 0],
         [1, 1]]
    ]


def piece7():
    return [
        [[1, 0, 0],
         [1, 1, 1]],
        [[1, 1],
         [1, 0],
         [1, 0]],
        [[1, 1, 1],
         [0, 0, 1]],
        [[0, 1],
         [0, 1],
         [1, 1]]
    ]


pieces = [piece1(), 
          piece2(), 
          piece3(), 
          piece4(), 
          piece5(), 
          piece6(), 
          piece7()]


def ints():
    return list(map(int, input().strip().split()))

c, p = ints() 
cols = ints()
piece = pieces[p - 1]
TOP = 110
field = [[0] * TOP for i in range(0, len(cols))]
for i in range(0, len(cols)):
    for j in range(0, cols[i]):
        field[c - i - 1][TOP - j - 1] = 1


def valid(field):
    for col in field:
        found = False
        for i in range(0, TOP):
            if found and col[i] == 0:
                return False
            found = found or col[i] == 1
    return True

ans = 0
for rot in piece:
    for i in range(0, c):
        for j in range(TOP - 1, -1, -1):
            if i + len(rot) > c or j + len(rot[0]) > TOP:
                continue

            before = defaultdict(dict)
            v = True
            for k in range(0, len(rot)):
                for h in range(0, len(rot[k])):
                    if rot[k][h]:
                        v = v and not field[i + k][j + h]
                        before[i + k][j + h] = field[i + k][j + h]
                        field[i + k][j + h] = 1
            if v:
                if valid(field):
                    ans += 1
            for k in range(0, len(rot)):
                for h in range(0, len(rot[k])):
                    if rot[k][h]:
                        field[i + k][j + h] = before[i + k][j + h] 
            if v:
                break

print(ans)
