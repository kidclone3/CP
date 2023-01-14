# https://codeforces.com/contest/1371/problem/B
t = int(input())
while(t > 0):
    t-=1
    n, r = map(int, input().split())
    ans = 0
    if (r < n):
        ans = (1+r)*r//2
    else:
        ans = 1 + n*(n-1)//2
    print(ans)