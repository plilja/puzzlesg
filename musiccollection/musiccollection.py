import sys

t = int(sys.stdin.readline())

for c in range(1, t + 1):
    n = int(sys.stdin.readline())
    songs = []
    for j in xrange(n):
        songs += [sys.stdin.readline().strip().lower()]

    print 'Case #%d:' % c

    for s in songs:
        best = 101 * 'X'
        for i in xrange(len(s)):
            for j in range(i, len(s) + 1):
                if j - i > len(best):
                    continue
                sub = s[i:j]
                if len(sub) == len(best) and sub >= best:
                    continue
                unique = True
                for s2 in songs:
                    if s == s2:
                        continue
                    if s2.find(sub) >= 0:
                        unique = False
                        break
                if unique:
                    best = sub

        if s.find(best) == -1:
            print ':('
        else:
            print '"%s"' % best.upper()
        
    
