import sys
from operator import itemgetter

attrs = map(str.strip, sys.stdin.readline().split(' '))

m = int(sys.stdin.readline())

songs = []

for i in range(0, m):
    line = map(str.strip, sys.stdin.readline().split(' '))
    songs += [tuple(line)]

n = int(sys.stdin.readline())

for i in range(0, n):
    attr = sys.stdin.readline().strip()
    idx = attrs.index(attr)
    songs = sorted(songs, key=itemgetter(idx))
    
    print ' '.join(attrs)

    for s in songs:
        print ' '.join(s)

    print ''
