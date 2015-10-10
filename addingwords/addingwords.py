import sys

variables = {}
reverse_variables = {}

for inp in map(str.strip, sys.stdin.readlines()):
    args = inp.split(' ')
    command = args[0]
    if command == 'clear':
        variables = {}
        reverse_variables = {}
    elif command == 'def':
        num = int(args[2])
        var = args[1]
        if var in variables:
            del reverse_variables[variables[var]]
            del variables[var]
        if num in reverse_variables:
            del variables[reverse_variables[num]]
            del reverse_variables[num]
        variables[var] = num
        reverse_variables[num] = var
    elif command == 'calc':
        r = 0
        is_var = True
        sign = 1
        is_unknown = False
        for var in args[1:]:
            if is_var:
                if not var in variables:
                    is_unknown = True
                    break
                else:
                    r += sign * variables[var]
            else:
                if var == '-':
                    sign = -1
                else:
                    sign = 1

            is_var = not is_var
        
        if is_unknown or r not in reverse_variables:
            print inp[5:], 'unknown'
        else:
            print inp[5:], reverse_variables[r]

    else:
        raise RuntimeError('Unknown command (%s)' % command)
