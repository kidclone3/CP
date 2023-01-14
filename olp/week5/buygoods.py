import math
n = int(input())

a = [0]*n
b = [0]*n

for i in range(n):
    a[i], b[i] = map(int, input().split())

dis = [0]*(2*n+5)

for i in range(2*n):
    dis[i+1] = math.sqrt((a[i%n] - a[(i+1)%n])**2 + (b[i%n] - b[(i+1)%n])**2)
    dis[i+1] += dis[i]

mn = 1e18
pos = 0
for i in range(1, n+1):
    if (dis[i+n-2] - dis[i-1] < mn):
        mn = dis[i+n-2] - dis[i-1]
        pos = i
print(pos)
print("%.6f" % (mn))
    