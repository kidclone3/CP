t = int(input())
while(t):
    t-=1
    n = int(input())
    ans = 0
    while(n > 1):
        n //= 5
        ans += n
    print(ans)
