import math
MOD =int(1e9+7)
n=int(input())
snt = dict()
primes = []
def sieve():
    check = [True]*(n+1)
    check[0] = check[1] = False
    for i in range(2, int(math.sqrt(n))+1):
        if check[i]:
            for j in range(i+i, n+1, i):
                check[j] = False
    for i in range(2, n+1):
        if check[i]:
            primes.append(i)
            snt[i]=0
def decompose(x):
    xx = x
    for i in primes:
        while(xx % i == 0):
            snt[i]+=1
            xx/=i
sieve()
# print(primes)
# now we calculate the power...
for i in range(2, n+1):
    if i in snt:
        snt[i]+=1
    else:
        decompose(i)
# print(snt)
ans=1
for i in primes:
    ans *= (snt[i]+1) % MOD
    ans %= MOD
print(ans)
