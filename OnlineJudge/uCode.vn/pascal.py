pascal = [1]
n = int(input())
for i in pascal:
    print(i, end=" ")
print()
if (n==1):
    exit()
for i in range (2, n+1):
    tmp = pascal.copy()
    for j in range (1, i-1):
        pascal[j] = tmp[j] + tmp[j-1]
    pascal.append(1)
    for i in pascal:
        print(i, end=" ")
    print() 