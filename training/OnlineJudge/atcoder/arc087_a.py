n = int(input())
a = [int(i) for i in input().split()]
mp = {}
for i in a:
    if mp.get(i) is None:
        mp[i] = 1
    else:
        mp[i] += 1
ans = 0
for i in mp:
    if (mp[i] < i):
        ans += mp[i]
    else:
        ans += mp[i] - i
print(ans)