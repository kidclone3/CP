import random
# print(1, 25)
n = 10
# a = [random.randint(1, 1000)]*n
a = [0]*n
a[0] = 6
x = 1
y = 2
for i in range(1, n):
    if (i % 2 == 0):
        a[i] = a[i-1]+x
        x+=1
    else:
        a[i] = a[i-1]-y
        y+=1
print(a)
    

