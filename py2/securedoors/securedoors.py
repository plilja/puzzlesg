import sys
import collections

log = collections.defaultdict(bool)

for e in sys.stdin.readlines()[1:]:
    op, pers = map(str.strip, e.split(" "))

    if op == "entry":
        entry = True
        message = "entered"
    elif op == "exit":
        entry = False
        message = "exited"
    else:
        raise Exception("Unknown operation")

    sys.stdout.write('%s %s' % (pers, message))
    if log[pers] == entry:
        sys.stdout.write(' (ANOMALY)')
    print ''

    log[pers] = entry

