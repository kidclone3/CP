
import random

n = int(1e5)
print(n)
for i in range(n):
    print(random.randint(1, n), end=" ")
print()
q = int(1e5)
print(q)
for i in range(q):
    # print(random)
    a = random.randint(1, n)
    b = random.randint(1, n)
    if b < a:
        a, b = b, a
    print(a, b, end="\n")
