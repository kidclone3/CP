import math
x, y = map(int, input().split())
bs = int(math.floor(math.log2(y/x)))
print(bs + 1)
# print(int(math.floor(math.log2(5))))