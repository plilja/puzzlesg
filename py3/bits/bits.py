t = int(input())

for _ in range(0, t):
    x = input()
    ans = 0
    for i in range(1, len(x) + 1):
        sub_entered = int(x[:i])
        as_binary = bin(sub_entered)
        ans = max(ans, len(list(filter(lambda bit: bit == '1', as_binary))))
    print(ans)
