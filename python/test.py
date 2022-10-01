def fac(x):
    ans = 1
    for i in range(1, x+1):
        ans*= i
    return ans
def nCr(n, r):
    top = fac(n)
    bot = fac(n-r)*fac(r)
    return top//bot

n = 2
m = 3
ans = 0
for i in range(n+1):
    for j in range(m+1):
        if i+j == 2:
            ans += nCr(n, j)*nCr(m, j)
# print(nCr(2, 2))
print(ans)
# print(nCr(5, 2))
assert ans == nCr(n+m, 2)
