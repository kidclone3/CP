n, m = map(int, input().split())
if (abs(n-m) > 1):
    print(0)
else:
    MOD = int(1e9+7)
    ans = 1
    for i in range(1, m + 1):
        ans = ans * i % MOD
    for i in range(1, n + 1):
        ans = ans * i % MOD
    if (m == n):
        ans = ans * 2 % MOD
    print(ans)