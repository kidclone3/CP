import math
t = int(input())
while (t>0):
    t-=1
    n = int(input())
    if (n%2==1):
        print("YES")
    else:
        tmp = int(math.log2(n))
        if (2**tmp == n):
            print("NO")
        else:
            print("YES")