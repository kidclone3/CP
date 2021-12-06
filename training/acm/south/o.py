n = int(input())
x = {}
y = {}
pair = {}
for i in range(n):
    a, b = map(int, input().split())
    if a not in x:
        x[a] = 1
    else:
        x[a] += 1
    if b not in y:
        y[b] = 1
    else:
        y[b] += 1
    if (a,b) not in pair:
        pair[(a,b)] = 1
    else:
        pair[(a, b)] += 1
ans = 0
for i in x.values():
    ans += i * (i-1) // 2
    
for i in y.values():
    ans += i * (i-1) // 2

for i in pair.values():
    ans -= i * (i-1) // 2

print(ans)
