digits = ['I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
tens = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']

def to_roman(n):
    return tens[n//10] + digits[n % 10 - 1]

b = input().strip()
for i in range(1, 100):
    r = to_roman(i)
    if sorted(r) == sorted(b):
        ans = r
        break

print(ans)
