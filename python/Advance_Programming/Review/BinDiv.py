inp = input().split(',')
ans = []
for i in inp:
    x = int(i, 2)
    if (x % 5 == 0):
        ans.append(i)
print(*ans, sep = ",")