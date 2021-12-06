from math import *

def digit(x):
    ans = 0
    while x:
        ans += x%10
        x//=10
    return ans
dig = 0
ans = 0
N = int(input())
for i in range(2, int(sqrt(N))+1):
    if N % i == 0:
        a = digit(i)
        if (a > dig):
            dig = a
            ans = i
        elif a == dig:
            ans = min(ans, i)
        b = digit(N//i)
        if (b > dig):
            dig = b
            ans = N//i
        elif b == dig:
            ans = min(ans, N//i)
a = digit(N)
if (a > dig):
    ans = N
print(ans)
