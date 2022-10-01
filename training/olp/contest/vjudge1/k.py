def solve():
    n, k = map(int, input().split())
    a = sorted([int(_) for _ in input().split()])
    if n == 1:
        return "YES"
    if min(a) > k or a[0] + a[-1] > k:
        return "NO"
    return "YES"


t = int(input())
while t:
    t -= 1
    print(solve())
