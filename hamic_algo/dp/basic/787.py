import sys

def solve(a):
    n = len(a)
    if (n == 0):
        return
    dp = [[0]*2 for i in range(n)]
    ans = a[0]
    for i in range(n):
        if not i:
            dp[i][0] = a[i]
            dp[i][1] = a[i]
        else:
            if a[i] >= 0:
                dp[i][0] = max(a[i], dp[i-1][0]*a[i])
                dp[i][1] = min(a[i], dp[i-1][1]*a[i])
            else:
                dp[i][0] = max(a[i], dp[i-1][1]*a[i])
                dp[i][1] = min(a[i], dp[i-1][0]*a[i])
        ans = max(ans, dp[i][0])
    print(ans)

for line in sys.stdin:
    # print(line)
    a = list(map(int, line.split()))
    a = a[:-1]
    solve(a)
