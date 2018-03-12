n = int(input())

runners = []
for i in range(0, n):
    [name, indv, relay] = input().strip().split()
    runners += [(name, float(indv), float(relay))]

best_time = float('inf')
best_team = []

for i in range(0, n):
    rem = runners[:i] + runners[i + 1:]
    rem_sorted = sorted(rem, key=lambda x: x[2])
    team = [runners[i]] + rem_sorted[0:3]
    time = 0
    for j in range(0, 4):
        if j == 0:
            time += team[j][1]
        else:
            time += team[j][2]
    if time < best_time:
        best_time = time
        best_team = team

print('%.9f' % best_time)
for (name, _, _) in best_team:
    print(name)
