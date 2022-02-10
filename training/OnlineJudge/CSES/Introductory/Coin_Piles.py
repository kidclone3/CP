def solve():
    a, b = input().split()
    a = int(a)
    b = int(b)
    if ((a + b) % 3 != 0 or max(a,b) - 2 * min(a, b) > 0):
        return "NO"
    return "YES"

t = int(input())
while(t > 0):
    t -= 1
    print(solve())