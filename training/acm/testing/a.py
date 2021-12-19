import math
t, m = map(int, input().split())
r = 3 + math.sqrt(11)
print(math.floor(pow(1+r, t)) % m)