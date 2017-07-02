class Timestamp:
    def __init__(self, h, m, s):
        self.h = h
        self.m = m
        self.s = s

    def __lt__(self, other):
        return self.ordinal() < other.ordinal()

    def ordinal(self):
        return self.s + self.m * 60 + self.h * 60*60

    @staticmethod
    def from_ordinal(o):
        h = o // (60 * 60)
        r1 = o % (60 * 60)
        m = r1 // 60
        s = r1 % 60
        return Timestamp(h, m, s)


def read_timestamp():
    [h, m, s] = map(int, input().split(':'))
    return Timestamp(h, m, s)

curr = read_timestamp()
bomb = read_timestamp()

if curr < bomb:
    r = Timestamp.from_ordinal(bomb.ordinal() - curr.ordinal())
else:
    midnight = Timestamp(24, 0, 0)
    r = Timestamp.from_ordinal(midnight.ordinal() - curr.ordinal() + bomb.ordinal())

print('%02d:%02d:%02d' % (r.h, r.m, r.s))


