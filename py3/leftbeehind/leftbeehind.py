while True:
    [x, y] = list(map(int, input().split()))
    if x == 0 and y == 0:
        break
    elif x + y == 13:
        print('Never speak again.')
    elif x == y:
        print('Undecided.')
    elif x < y:
        print('Left beehind.')
    else:
        print('To the convention.')
