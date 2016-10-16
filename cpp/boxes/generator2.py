import random

# These files will be over 10mb, hence I don't want to store them in the repo.

n = 100000
q = 200000

print(n)
for i in range(1, n + 1):
    if i == n:
        print('0', end = '')
    else:
        print(i + 1, end = ' ')
print()

print(q)
for i in range(0, q):
    m = random.randint(1, 20)
    print(m, end = ' ')
    for j in range(0, m):
        print(random.randint(1, n), end = ' ')
    print()
