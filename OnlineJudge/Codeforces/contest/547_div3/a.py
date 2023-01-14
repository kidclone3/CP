n, m = map(int ,input().split())
if (n > m or m % n != 0):
    print(-1)
    exit()
tmp = m//n
ans = 0
while(tmp > 1 and tmp % 2 == 0): 
    tmp //= 2
    ans += 1
while(tmp > 1 and tmp % 3 == 0):
    tmp //= 3
    ans += 1
if (tmp != 1):
    print(-1)
else:
    print(ans)
