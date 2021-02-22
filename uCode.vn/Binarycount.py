def toHop(n, k):
    ans = 1
    kk = 1
    for i in range (2, k+1):
        kk *= i
    for i in range (n-k+1, n+1):
        ans *= i
    return ans // kk
# a = []
n = int(input())
ans = 1 + n
for i in range (2, (n+1)//2+1):
    tmp = 0
    nn = n-i
    for j in range (1, i):
        tmp += toHop(nn + j, j)
    ans += toHop(n, i) - tmp
    # print (ans, tmp, toHop(n, i))
    
print(ans)