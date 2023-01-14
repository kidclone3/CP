import random
N = int(1e4)
n = random.randint(1, N)
q = random.randint(1, N-10)
print(n, q)
for i in range(n):
    x = random.randint(1, N)
    print(x, end = " ")
print()
for i in range(q):
    r = random.randint(2, n-1)
    l = random.randint(1, r-1)
    print(l, r)
    
