def solve():
    x, n = map(int, input().split())
    n_4 = n//4*4
    n_4_1 = (n//4-1)*4
    k4_0 = 0
    k4_1 = 0
    k4_2 = 0
    k4_3 = 0
    if (n >= 4):
        k4_0 = (0 + n_4) *(n_4//4+1) // 2
        k4_1 = (1 + n_4_1 + 1) * (n//4) // 2
        k4_2 = (2 + n_4_1 + 2) * (n//4) // 2
        k4_3 = (3 + n_4_1 + 3) * (n//4) // 2
    if (n >= n_4 + 1):
        k4_1 += n_4 + 1
    if (n >= n_4 + 2):
        k4_2 += n_4 + 2
    if (n >= n_4 + 3):
        k4_3 += n_4 + 3
    ans = k4_0 + k4_1 - k4_2 -k4_3
    if (x % 2 == 0): ans = - ans
    print(x + ans)

t = int(input())
while(t):
    t-=1
    solve()

    