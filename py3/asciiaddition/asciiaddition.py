zero = '''xxxxx
x...x
x...x
x...x
x...x
x...x
xxxxx'''

one = '''....x
....x
....x
....x
....x
....x
....x'''

two = '''xxxxx
....x
....x
xxxxx
x....
x....
xxxxx'''

three = '''xxxxx
....x
....x
xxxxx
....x
....x
xxxxx'''

four = '''x...x
x...x
x...x
xxxxx
....x
....x
....x'''

five = '''xxxxx
x....
x....
xxxxx
....x
....x
xxxxx'''

six = '''xxxxx
x....
x....
xxxxx
x...x
x...x
xxxxx'''

seven = '''xxxxx
....x
....x
....x
....x
....x
....x'''

eight = '''xxxxx
x...x
x...x
xxxxx
x...x
x...x
xxxxx'''

nine = '''xxxxx
x...x
x...x
xxxxx
....x
....x
xxxxx'''

plus = '''.....
..x..
..x..
xxxxx
..x..
..x..
.....'''

ascii_to_digit = {zero : 0, one : 1, two : 2, three : 3, four : 4, five : 5, six : 6, seven : 7, eight : 8, nine : 9}
digit_to_ascii = {0 : zero, 1 : one, 2 : two, 3 : three, 4 : four, 5 : five, 6 : six, 7 : seven, 8 : eight, 9 : nine}

def tokenize(inp):
    if len(inp[0]) > 5:
        rem_inp = [s[6:] for s in inp]
        token = [s[:5] for s in inp]
        return ['\n'.join(token)] + tokenize(rem_inp)
    else:
        return ['\n'.join(inp)]


def untokenize(digits):
    if len(digits) == 1:
        return digits[0].split()
    else:
        digit = digits[0].split()
        rem = untokenize(digits[1:])
        return [digit[i] + '.' + rem[i] for i in range(0, 7)]


inp = [input().strip() for i in range(0, 7)]
tokens = tokenize(inp)
plus_idx = tokens.index(plus)

a = [ascii_to_digit[s] for s in tokens[:plus_idx]]
b = [ascii_to_digit[s] for s in tokens[plus_idx + 1:]]
a = int(''.join(map(str, a)))
b = int(''.join(map(str, b)))
res = list(map(lambda d: digit_to_ascii[ord(d) - ord('0')], str(a + b)))
print('\n'.join(untokenize(res)))
