def solve(page, book, favourable_endings, cache):
    if page in favourable_endings:
        return 1
    elif page in cache:
        return cache[page]
    else:
        ans = 0
        for option in book[page]:
            ans += solve(option, book, favourable_endings, cache)
        cache[page] = ans
        return ans


t = int(input())

for i in range(0, t):
    s = int(input())
    favourable_endings = set()
    book = {}
    for j in range(0, s):
        xs = input().strip().split(' ')
        page = int(xs[0])
        if len(xs) == 4:
            options = list(map(int, xs[1:]))
            book[page] = options
        elif xs[1] == 'favourably':
            favourable_endings |= {page}
        else:
            book[page] = []
    r = solve(1, book, favourable_endings, {})
    print(r)


