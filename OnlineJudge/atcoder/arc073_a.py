n, T = map(int, input().split())
t = [int(i) for i in input().split()]
curr = 0
ans = 0
for i in range(n):
    if (t[i] >= curr):
        ans += T
    else:
        d = t[i] + T - curr
        ans += d
    curr = t[i] + T
print(ans)
