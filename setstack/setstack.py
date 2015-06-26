import sys
from collections import deque 
import operator

t = int(sys.stdin.readline())
        
        
class ParamExpr():
    def __init__(self, children):
        self.children = children
        self.hash_cached = None

    def __eq__(self, other):
        return hash(self.children) == hash(other.children)

    def __hash__(self):
        if (self.hash_cached == None):
            self.hash_cached = hash(self.children)
        return self.hash_cached

    def __and__(self, other):
        return ParamExpr(self.children & other.children)

    def __or__(self, other):
        return ParamExpr(self.children | other.children)

    def __len__(self):
        return len(self.children)
 

for i in xrange(t):
    n = int(sys.stdin.readline())
    stack = deque()
    for j in xrange(n):
        op = sys.stdin.readline().strip()
        if op == 'PUSH':
            stack.append(ParamExpr(frozenset()))
        elif op == 'DUP':
            stack.append(stack[-1])
        elif op == 'INTERSECT':
            a = stack.pop()
            b = stack.pop()
            stack.append(a & b)
        elif op == 'ADD':
            a = stack.pop()
            b = stack.pop()
            stack.append(b | ParamExpr(frozenset([a])))
        elif op == 'UNION':
            a = stack.pop()
            b = stack.pop()
            stack.append(a | b)

        print len(stack[-1])

    print '***'
 
