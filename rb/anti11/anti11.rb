M = 10**9 + 7

def solve(n)
    m0 = 1
    m1 = 1
    for i in 2..n
        tmp = m0
        m0 = (m0 + m1) % M
        m1 = tmp
    end
    return (m0 + m1) % M
end

t = gets.to_i
for _ in 1..t
    puts solve gets.to_i
end
