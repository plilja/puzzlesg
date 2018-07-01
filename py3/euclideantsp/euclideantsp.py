from math import *

EPS = 1e-10
SQRT_2 = sqrt(2)

def time(n, p, s, v, c):
    compute_time = n * (log(n, 2)**(c * SQRT_2)) / (p * 1e9)
    travel_time = s * (1 + 1 / c) / v
    return compute_time + travel_time


def deriv(f, x):
    dx = 1e-6
    dy = f(x + dx) - f(x)
    return dy / dx


def newton(f, x0):
    x = float('inf')
    x_next = x0
    count = 0 # fallback in case it doesn't converge
    while count < 2000 and abs(x - x_next) > EPS:
        x = x_next
        y = f(x)
        d = deriv(f, x)
        if d < EPS:
            return x
        x_next = x - y / d
        count += 1
    return x


def solve(n, p, s, v):
    r_c = 1
    r_t = float('inf')
    # Ugly heuristic, try a couple of different starting c's to avoid getting stuck in a local maxima
    for i in range(1, 25):
        c = newton(lambda x: deriv(lambda u: time(n, p, s, v, u), x), 0.4 * i)
        time_taken = time(n, p, s, v, c)
        if time_taken < r_t:
            r_c = c
            r_t = time_taken
    return r_t, r_c


[n, p, s, v] = list(map(float, input().strip().split()))
t, c = solve(n, p, s, v)
print('%.8f %.8f' % (t, c))
