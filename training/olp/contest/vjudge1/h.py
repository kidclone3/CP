t = int(input())
while t:
    t -= 1 
    n, k = map(int, input().split())
    a = sorted([int(_) for _ in input().split()])
    for i in range(k):
        if (a[i] < 0):
            a[i] = - a[i]
        else:
            break
    a = sorted(a)
    ans = 0
    for i in a:
        if i >= 0:
            ans += i
    print(ans) 
