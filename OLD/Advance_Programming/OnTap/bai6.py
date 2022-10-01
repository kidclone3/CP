a = int(input())
sum = 0
temp = a
for i in range(4):
    sum += temp
    temp *= 10
    temp += a
print(sum)