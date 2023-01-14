ans = 0
def back(x):
    if x == 0:
        global ans
        ans += 1
        return
    for i in range(x, 0, -1):
        back(x-i)

n = int(input())
back(n)
print(ans)