n = int(input())
a = [int(i) for i in input().split()]
# Chia ra 2th:
# + - + - + - + --> TH1 => i % 2 == 0 ~ +; else -
# - + - + - + - --> TH2 
ans = int(1e18)
for r in range(0, 2):
    res = 0
    curr = 0
    for i in range(n):
        curr += a[i]
        if (i % 2 == r):
            if (curr <= 0):
                d = 1 - curr
                res += abs(d)
                curr = 1
        else:
            if (curr >= 0):
                d = -1 - curr
                res += abs(d)
                curr = -1
    ans = min(ans, res)
print(ans)
