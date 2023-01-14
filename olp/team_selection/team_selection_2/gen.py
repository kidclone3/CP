import random
n = 400
print(n)
for i in range(n):
    for j in range(n):
        print(random.randint(-1000, 1000), end = " ")
    print()