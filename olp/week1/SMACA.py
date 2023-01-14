def prod(x):
    ans = 1
    for i in x:
        ans *= i
    return ans
m, n = map(int, input().split())

k = prod([int(i) for i in input().split()])
ans = []
for j in range(1, n+1):
  product = prod([int(i) for i in input().split()])
  # product = math.prod(x)
  if (k % product == 0):
      ans.append(j)

print(len(ans))
print(*ans)
    