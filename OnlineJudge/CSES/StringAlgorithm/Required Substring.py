MOD = int(1e9+7) 
def powMod(x, p):
    ans = 1 
    while p:
        if p&1:
            ans = ans * x 
            ans %= MOD
        x = x*x 
        p >>= 1
    return ans
# print(powMod(2, 5))
def solve():
    n = int(input())
    s = input()
    m = len(s)
    if n < m:
        return 0
    if n == m:
        return 1 
    t = n-m 
    return (t+1)*powMod(26, t) % MOD

print(solve())
