import sys


def read_input():
    lines = map(str.strip, sys.stdin.readlines())
    r = [[]]
    for line in lines:
        if not line:
            r += [[]]
        else:
            r[-1] += [line]
    return r


def reverse_sorted(dictionary):
    return sorted(dictionary, key=lambda x: ''.join(reversed(x)))


def print_right_alligned(words):
    max_len = max(map(len, words))
    for w in words:
        print((max_len * ' ' + w)[-max_len:])


first = True
for dictionary in read_input():
    if not first:
        print()
    print_right_alligned(reverse_sorted(dictionary))
    first = False
