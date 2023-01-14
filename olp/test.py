n = 6
k = 4
res = []
x0 = []
sum = 0

def backtrack(begin, pos, remainder):
    global n, k, res, x0, sum
    if pos == k:
        if (sum == n):
            res.append(x0.copy())
        return
    for i in range(begin, remainder+1):
        sum += i
        x0.append(i)
        backtrack(i, pos+1, remainder - i)
        sum -= i
        x0.pop()
for n in range(1, 50):
    ans = 0
    res = []
    x0 = []
    sum = 0
    for k in range(1, n+1):
        backtrack(1, 0, n)
    print(len(res))
# print(res)