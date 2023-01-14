n, m = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort()
i = 0
j = len(a)-1
while(j >= 0 and a[j] > m):
    j-=1
ans = 0
while(i < j):
    if (a[i] + a[j] <= m):
       ans+=1
       i+=1
       j-=1
    else:
        ans+=1
        j-=1
if (i == j):
    ans+=1
print(ans)