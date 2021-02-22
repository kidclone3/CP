match = []
for i in range (7):
    a, b = [int(i) for i in input().split()]
    match.append([a, b])
A = B = 0
for a, b in match:
    if (a>b):
        A+=1
    if (b>a):
        B+=1
    if (A==4 or B == 4):
        break
print(A, B)