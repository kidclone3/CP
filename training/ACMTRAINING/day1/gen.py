import random
m = 10000 
n = 10000
print(m, n)
a = [0]*m 
print(*a)
for i in range(m):
    # l = random.randint(0, m) 
    # r = random.randint(0, m) 
    l = 0 
    r = m-1
    if l > r:
        l, r = r, l;
    x = random.randint(0, int(1e4)) 
    print(l, r, x)

