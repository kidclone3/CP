n = int(input())
MOD = 998244353
a = [int(i) for i in input().split()]

def f(x):
    sum = 0
    i = 1
    while(x > 0):
        dig = x % 10
        sum += dig*11*i
        i*=100
        x //= 10
    return sum
ans = 0
for i in a:
    ans += n * f(i)
print(ans % MOD)
