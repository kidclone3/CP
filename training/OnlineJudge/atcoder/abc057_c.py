import math
def f(a, b):
    return max(len(str(a)), len(str(b)))
n = int(input())
ans = int(1e18)
for i in range(1, int(math.sqrt(n))+2):
    if n % i == 0:
        ans = min(ans, f(i, n//i))
print(ans)
