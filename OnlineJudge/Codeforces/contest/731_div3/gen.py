import random
print(1)
n = int(3e5)
print(n)
for i in range(n):
    print(i+1, sep = " ")
for i in range(n):
    print(random.randint(1, int(1e9)), sep = " ")

