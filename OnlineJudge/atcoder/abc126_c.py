import math
n, k = map(int, input().split())
ans = 0
if (n >= k):
    ans += (n-k+1)/n
for i in range(1, min(n, k) + 1):
    ans += (1/n) * pow(0.5, int(math.log2((k-1)/i)))
print(ans)