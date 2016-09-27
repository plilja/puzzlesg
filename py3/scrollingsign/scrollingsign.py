n = int(input())

for i in range(0, n):
    (n, w) = list(map(int, input().split()))
    ans = n
    prev = input()
    for j in range(0, w - 1):
        s = input()
        match = False
        for k in range(n, 0, -1):
            if s[:k] == prev[-k:]:
                ans += (n - k)
                match = True
                break
        if not match:
            ans += n
        prev = s
    print(ans)
