
MOD = int(1e9) + 7
# dat Un = Vn - b
# => Un = 2^(n-1)*(a+b) - b
# Dinh ly fermat nho: 2^(MOD-1) === 1 % MOD
# => p = (n-1) % (MOD - 1) => 2^(n-1) === 2^p % MOD
def powMod(x, n):
    ans = 1
    x %= MOD
    while n:
        if n % 2 == 1:
            ans = ans * x % MOD
        x = x * x % MOD
        n //= 2
    return ans

t = int(input())
while t:
    t -= 1
    a, b, n = map(int, input().split())
    p = (n-1) % (MOD-1)

    pp = powMod(2, p)

    ans = pp * (a+b) - b 
    print(ans % MOD)