def check(x):
    odd = even = 0
    for i in range(len(x)):
        if (i % 2 == 1):
            even+=int(x[i])
        else:
            odd+=int(x[i])
    ans = even+ 3*odd
    # print(even, odd)
    return (ans % 10 == 0)
x = input()
ans = None
m = 10

for i in range(0, 10):
    y=x[:11] + chr(i + ord('0'))
    if check(y):
        # print(y)
        if (abs(int(y)-int(x)) < m):
            m= abs(int(y)-int(x))
            # print(abs(int(y)-int(x)))
            ans = y
print(ans)