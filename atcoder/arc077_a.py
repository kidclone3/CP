n = int(input())
a = [int(i) for i in input().split()]
ans = [0]*n
l = 0
r = n-1
if (n % 2 == 0):
    # Duyet nguoc tu cuoi, ko can xoay tua.
    for i in range(n-1, -1, -1):
        if (i % 2 == 1):
            ans[l] = a[i]
            l+=1
        else:
            ans[r] = a[i]
            r-=1
else:
    for i in range(n-1, -1, -1):
        if (i % 2 == 0):
            ans[l] = a[i]
            l+=1
        else:
            ans[r] = a[i]
            r-=1
for i in ans:
    print(i, end=" ")