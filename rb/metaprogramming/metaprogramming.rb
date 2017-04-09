env = Hash.new
while s = gets
    args = s.split(' ')
    command = args[0]
    if command == 'define'
        env[args[2]] = args[1].to_i
    elsif command == 'eval'
        var1 = args[1]
        op = args[2]
        var2 = args[3]
        if !env.key?(var1) or !env.key?(var2)
            puts 'undefined'
        elsif op == '='
            puts (env[var1] == env[var2])
        elsif op == '<'
            puts (env[var1] < env[var2])
        elsif op == '>'
            puts (env[var1] > env[var2])
        else
            raise 'Unknown operator ' + op
        end
    else
        raise 'Unknown command ' + command
    end
end
