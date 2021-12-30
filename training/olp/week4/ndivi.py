import math
t = int(input())
while (t):
    t -= 1
    n, k = map(int, input().split())
    ans = k
    while (k > 0):
        k //= n
        tmp = n - (ans%n)
        if tmp - 1 < k:
            ans += tmp
            k -= tmp-1
            ans += k
        else:
            ans += k
            k = 0
    print(ans)