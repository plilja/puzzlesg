import sys

board = map(str.strip, sys.stdin.readlines())

queens = set()

for y in range(0, 8):
    for x in range(0, 8):
        if board[y][x] == '*':
            queens |= {(y, x)}

invalid = len(queens) != 8

for y1, x1 in queens:
    for y2, x2 in queens - {(y1, x1)}:
        invalid = invalid or y1 == y2
        invalid = invalid or x1 == x2
        invalid = invalid or (x1 - x2 == y1 - y2)
        invalid = invalid or (x1 - x2 == -(y1 - y2))

if invalid:
    print 'invalid'
else:
    print 'valid'
