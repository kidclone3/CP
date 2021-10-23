n = int(input())
a = []
for i in range(n):
    tmp = input()
    a.append(tmp)
a.sort()
print(*a, sep = "")