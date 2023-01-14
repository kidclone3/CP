n = int(input())
a = [0]*n
# thay vi vi tri 2, ta con vi tri 1 (bat dau tu 0)
for i in range(n):
    a[i] = int(input()) - 1
def solve(a, n):
    ck = [0]*(n+1)
    ck[0] = 1
    ans = 0
    next = a[0]
    while(next != 1):
        if ck[a[next]] == 0:
            ans+=1
            ck[next] = 1
            next = a[next]
        else:
            return -1
    return ans + 1
print(solve(a, n))
