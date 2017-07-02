class Tree:

    def __init__(self):
        self.value = None
        self.size = 0


    def add(self, value):
        self.size += 1
        if not self.value:
            self.value = value
            self.left = Tree()
            self.right = Tree()
        elif self.value > value:
            self.left.add(value)
        else:
            assert(self.value < value)
            self.right.add(value)


    def __eq__(self, other):
        if self.size != other.size:
            return False
        elif self.size == 0:
            assert(other.size == 0)
            return True
        else:
            return self.left == other.left and self.right == other.right
        

def ints():
    return list(map(int, input().strip().split()))


[n, k] = ints()
shapes = []
for _ in range(0, n):
    t = Tree()
    for layer in ints():
        t.add(layer)
    if t not in shapes:
        shapes += [t]

print(len(shapes))
