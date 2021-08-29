n = int(input())
def solve(x):
    ans = 0
    while(x % 2 ==0):
        ans+=1
        x//=2
    return(ans)
ans = -1
tmp = -1
for i in range(1, n+1):
    tmp2 = solve(i)
    if (tmp2 > tmp):
        ans = i
        tmp = tmp2
print(ans)