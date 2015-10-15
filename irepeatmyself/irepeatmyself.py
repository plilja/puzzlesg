import sys

def strip_newline(s):
    return s[:-1]

for inp in map(strip_newline, sys.stdin.readlines()[1:]):
    for i in range(1, len(inp) + 1):
        if (inp[:i] * (len(inp)/i + 1)).startswith(inp):
            print i
            break
