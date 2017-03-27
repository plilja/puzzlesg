from collections import Counter

s = input()
digits = Counter([int(i) for i in s])

m = len(s) + 1
min_digit = 0
for d in digits:
    if digits[d] < m and d != 0:
        m = digits[d]
        min_digit = d

non_present_digits = [i for i in range(0, 10) if digits[i] == 0]

if non_present_digits == [0]:
    print(10)
elif non_present_digits:
    if non_present_digits[0] == 0:
        non_present_digits = non_present_digits[1:]
    print(non_present_digits[0])
else:
    if digits[0] + 1 <= m:
        print('1' + '0' * (digits[0] + 1))
    else:
        print(str(min_digit) * (m + 1))
