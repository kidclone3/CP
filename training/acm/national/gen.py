import random
n = 4
print(n)
for i in range(n*n):
    print(random.randint(1, n+1), end=" ")
