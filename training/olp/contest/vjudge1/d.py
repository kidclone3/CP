t = int(input())
while t:
    t-=1 
    n = int(input())
    a = [int(_) for _ in input().split()] 
    ans = len(set(a))
    if min(a) == 0:
        ans -= 1 
    print(ans)

    
