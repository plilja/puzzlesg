def solve(e, c):
    if e < c:
        return 0
    else:
        buy = e // c
        return buy + solve(e - buy*c + buy, c)

[e, f, c] = list(map(int, input().strip().split()))
print(solve(e + f, c))
