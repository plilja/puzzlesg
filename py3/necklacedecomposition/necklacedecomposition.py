def necklace(s):
    rot = []
    for i in range(0, len(s)):
        rot += [s[i:] + s[:i]]
    return min(rot)


def necklace_decomposition(s, pre = '9', cache = {}):
    if (s, pre) in cache:
        return cache[(s, pre)]
    for i in range(1, len(s)):
        substring = s[:i]
        if substring < pre and substring == necklace(substring) and pre + substring != necklace(pre + substring):
            sub = necklace_decomposition(s[i:], substring, cache)
            if sub:
                r = [substring] + sub
                cache[(s, pre)] = r
                return r
    if s < pre and necklace(s) == s and pre + s != necklace(pre + s):
        cache[(s, pre)] = [s]
        return [s]
    cache[(s, pre)] = None
    return None


n = int(input())
for i in range(0, n):
    s = input()
    for n in necklace_decomposition(s):
        print('(%s)' % n, end = '')
    print()
