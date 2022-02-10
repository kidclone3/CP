n = int(input())
a = []
for i in range(n):
    tmp = input()
    a.append(tmp)
x = a[0]
ans = []
for i in x:
    check = True
    for j in range(1, n):
        if a[j].find(i) != -1:
            a[j] = a[j].replace(i,"",1)
        else:
            check = False
            break
    if check:
        ans.append(i)
ans.sort()
for i in ans:
    print(i,end="")
