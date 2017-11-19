n = int(input())

for _ in range(0, n):
    digits = input().strip().split(',')
    ans = 0
    for j in range(0, len(digits)):
        c = digits[-j - 1].strip()
        if c == '':
            d = 0
        else:
            d = int(c)
        ans += d * 60**j
    print(ans)
