import math
n = 1000
a = [0]*n
a[0] = 1
for i in range(1, 21):
    # a[i] = a[i-1] + a[i-2]
    a[i] = 2**(i-1)
    # print(a[i], end = " ")

t = int(input())
while(t):
    t-=1
    s = input()
    # print(s)
    sz = len(s)
    ans = 0
    for i in range(0, n-25):
        # a[i+sz] = 0
        if (i < sz)
        for j in range(1, sz+1):
            a[i+sz] += a[i+sz-j]
        ans += 0.5**(i+sz)*a[i+sz]*(i+sz)

    print(math.ceil(ans))