n = int(input())
a = [int(i) for i in input().split()]
ans = 0
cnt = 1
a.sort()
for i in range(1, len(a)):
    if (a[i] == a[i-1]):
        cnt+=1
    else:
        if (cnt != 1):
            ans += cnt
        cnt = 1
if (cnt != 1): ans += cnt
print(ans)
