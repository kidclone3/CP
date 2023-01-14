def solve(n):
    peak = 2/(1-n/180.0)
    # print(peak)
    tmp = round(peak)
    # print(tmp)
    if (tmp < 3 or (abs(peak - tmp) > 1e-9)):
        print("NO")
    else:
        print("YES")
t = int(input())
for i in range(0, t):
    n = int(input())
    solve(n)