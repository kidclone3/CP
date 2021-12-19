import random
n = 5*int(1e6+5)
print(n)
for i in range(n):
    print(random.randint(1, int(3*1e4)), end = " ")
