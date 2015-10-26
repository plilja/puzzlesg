import sys
from collections import defaultdict

lines = map(str.strip, sys.stdin.readlines())

N = int(lines[0])

g = defaultdict(list)

for line in lines[1:N+1]:
    args = line.split(' ')
    station = args[0]
    for conn in args[1:]:
        g[station] += [conn]
        g[conn] += [station]


def dfs(g, fr, to, vis):
    if fr == to:
        return [fr]
    for conn in g[fr]:
        if not conn in vis:
            s = dfs(g, conn, to, vis | {conn})
            if s != None:
                return [fr] + s


fr, to = lines[-1].split(' ')

r = dfs(g, fr, to, {fr})

if r == None:
    print 'no route found'
else:
    for stop in r:
        print stop,
    print ''
