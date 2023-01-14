t = int(input())
while t:
    t -= 1 
    n = int(input())
    ans = 0
    while n:
        n -= 1
        x = int(input()) 
        ans ^= x 
    print(ans)
