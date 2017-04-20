import sys
from collections import defaultdict

day = 0
for s in sys.stdin.readlines():
    args = s.split()
    command = args[0]
    if command == 'OPEN':
        day += 1
        customers = defaultdict(lambda: 0.0)
        entry_time = {}
    elif command == 'CLOSE':
        print('Day %d' % day)
        for customer in sorted(customers.keys()):
            print('%s $%.2f' % (customer, customers[customer]))
        print()
    elif command == 'ENTER':
        entry_time[args[1]] = int(args[2])
    else:
        assert(command == 'EXIT')
        time = int(args[2]) - entry_time[args[1]] 
        customers[args[1]] += time * 0.1
