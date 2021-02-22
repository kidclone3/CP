a, b, c, d = [int(i) for i in input().split()]
man = [int(i) for i in input().split()]
aa = a+b
cc = c+d
for i in range(len(man)):
    ans = 0
    if ((man[i] % aa) - a <= 0):
        ans+=1
    if ((man[i] % cc) - c <= 0):
        ans+=1
    if (ans == 0):
        print("none", end=" ")
    if (ans == 1):
        print("one", end=" ")
    if (ans == 2):
        print("both", end=" ")
