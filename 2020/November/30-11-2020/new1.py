a, b, k = input().split()
a = int(a)
b = int(b) 
k = int(k)
aa = int(a ** (1.0/2))
bb = int(b ** (1.0/2))
aaa = int(a ** (1.0/3))
bbb = int(b ** (1.0/3))
count = 0
for i in range (aa, bb + 1):
    for j in range (aaa, bbb + 1):
        if abs (i * i - j * j * j) <= k:
            count+=1
            # print(i, k)
print(count)