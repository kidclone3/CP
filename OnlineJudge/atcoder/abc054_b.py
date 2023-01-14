n, m = map(int, input().split())
a = []
b = []
for i in range(n):
    s = input()
    a.append(s)
for i in range(m):
    s = input()
    b.append(s)
def solve():
    for i in range(n-m+1):
        for j in range(n-m+1):
            if a[i][j] == b[0][0]:
                check1 = True
                for x in range(m):
                    if not check1:
                        break
                    for y in range(m):
                        if (a[i+x][j+y] != b[x][y]):
                            check1 = False
                            break
                if check1:
                    return "Yes"
    return "No"
print(solve())
