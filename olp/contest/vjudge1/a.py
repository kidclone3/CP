t = int(input())
mp = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
while t > 0:
    t-=1
    a, b = map(int, input().split())
    a += b 
    ans = 0
    while a > 0:
        # print(a%10, mp[a%10])
        ans += mp[a%10]
        a //= 10 
    print(ans)
