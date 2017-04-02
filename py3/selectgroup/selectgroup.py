import sys


def main():
    groups = {}
    for s in map(str.strip, sys.stdin.readlines()):
        args = s.split()
        if args[0] == 'group':
            name = args[1]
            n = int(args[2])
            members = args[3:] 
            assert name not in ['group', 'intersection', 'union', 'difference']
            groups[name] = frozenset(members)
        else:
            stack = args
            for i in range(0, len(stack)):
                if args[i] in groups:
                    stack[i] = groups[args[i]]
            ans = run(stack)
            print(' '.join(sorted(ans)))


def run(stack):
    if stack[0] in ['intersection', 'union', 'difference']:
        op = stack[0]
        stack.pop(0)
        a = run(stack)
        b = run(stack)
        if op == 'intersection':
            stack.insert(0, a & b)
        elif op == 'union':
            stack.insert(0, a | b)
        elif op == 'difference':
            stack.insert(0, a - b)
        return run(stack)
    else:
        return stack.pop(0)


main()
