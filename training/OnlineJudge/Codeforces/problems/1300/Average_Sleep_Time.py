# https://codeforces.com/contest/808/problem/B
n, k = map(int, input().split())
a = [int(i) for i in input().split()]
sum = 0.0
avg = 0.0
i = 0
while (i < k):
    sum += a[i]
    i+=1
avg += sum
while(i < n):
    sum -= a[i-k]
    sum += a[i]
    avg += sum
    i += 1
avg /= (n-k+1)
print(avg)