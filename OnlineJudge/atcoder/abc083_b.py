def digit(x):
    sum = 0
    while(x > 0):
        sum += x%10
        x//=10
    return sum
n, a, b = map(int, input().split())
ans = 0
for i in range(1, n+1):
    if (a <= digit(i) <= b):
        ans += i
print(ans)