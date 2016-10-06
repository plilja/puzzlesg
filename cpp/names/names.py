def solve(name):
    ans = float('inf')
    n = len(name)
    if n <= 1:
        return 0
    for j in range(0, 2):
        for i in range(n//2 - j, n - 1):
            diff = palindrome_diff(name, i, i + j)
            letters_to_add = abs(n - 2*i - 1 - j)
            ans = min(ans, diff + letters_to_add)
    return ans

def palindrome_diff(name, i1, i2):
    res = 0
    n = len(name)
    j = 0
    while i1 - j >= 0 and i2 + j < n:
        if name[i1 - j] != name[i2 + j]:
            res += 1
        j += 1
    return res

name = input()
print(solve(name))
