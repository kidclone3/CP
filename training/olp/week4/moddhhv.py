import math
a = [int(i) for i in input().split()]
a.sort()
tmp1 = a[1] - a[0]
tmp2 = a[2] - a[0]
print(math.gcd(tmp1, tmp2))