one_to_twenty = ['one', 'two', 'three', 
        'four', 'five', 'six', 
        'seven', 'eight', 'nine', 
        'ten', 'eleven', 'twelve', 
        'thirteen', 'fourteen', 'fifteen', 
        'sixteen', 'seventeen', 'eighteen', 
        'nineteen']
tens = ['twenty', 'thirty', 'forty', 
        'fifty', 'sixty', 'seventy', 
        'eighty', 'ninety']
hundreds = ['onehundred', 'twohundred', 'threehundred', 
        'fourhundred', 'fivehundred', 'sixhundred', 
        'sevenhundred', 'eighthundred', 'ninehundred']


def number_as_str(i):
    if i == 0:
        return ''
    elif i <= 19:
        return one_to_twenty[i - 1]
    elif i < 100:
        return tens[i // 10 - 2] + number_as_str(i % 10)
    else:
        assert(i < 1000)
        return hundreds[i // 100 - 1] + number_as_str(i % 100)


def solve(sentence):
    without_space = sentence.replace(' ', '')
    for i in range(1, 1001):
        num = number_as_str(i)
        s = without_space.replace('$', num)
        if len(s) == i:
            return sentence.replace('$', num)
    raise ValueError('No solution exists')


n = int(input())
words = [input() for i in range(0, n)]
print(solve(' '.join(words)))
