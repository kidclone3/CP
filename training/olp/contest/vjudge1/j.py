def solve():
    n = int(input())
    a = [0] * n
    for i in range(n):
        a[i] = [int(_) for _ in input().split()]
    row = [10000]*n 
    col = [10000]*n 
    for i in range(n):
        for j in range(n):
            row[i] = min(row[i], a[i][j])
            col[j] = min(col[j], a[i][j])
    for i in range(n):
        if row[i] != 0 or col[i] != 0:
            return "NO"
    return "YES" 
t = int(input())
while t:
    t -= 1
    print(solve())

