arr = []
n = int(input())
# s=input()
# arr=[s.split]
arr = [int(i) for i in input().split()]
sum = []
sum.append(arr[0])
# print(sum[0])
m = int(1e18)

for i in range(1, n):
    sum.append(sum[i-1]+arr[i])

for i in range(0, n):
    m = min(m, abs(sum[n-1]-2*sum[i]))

print(m)
