import random
N = 10
n = N
m = N
a = [i for i in range(1, n+1)]
random.shuffle(a)
print(n, m)
print(*a)
for i in range(m):
    print(random.randint(1, n), end = " ")
    k = "lr"[random.randint(1, 2) % 2]
    print(k, end = "\n")