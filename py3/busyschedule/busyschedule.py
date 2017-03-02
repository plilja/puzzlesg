import re

while True:
    n = int(input())
    if n == 0:
        break
    first = False
    appointments = []
    for i in range(0, n):
        inp = input()
        h, m, z = re.match(r'(\d\d?):(\d\d) (....)', inp).groups()
        if h == '12':
            appointments += [(z, 0, int(m))]
        else:
            appointments += [(z, int(h), int(m))]

    appointments.sort()
    for z, h, m in appointments:
        if (z == 'p.m.' and h == 0) or (z == 'a.m.' and h == 0 and m == m):
            print('12:%02d %s' % (m, z))
        else:
            print('%d:%02d %s' % (h, m, z))
    print()
