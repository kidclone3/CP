p, x, y = map(int, input().split())
s = y
while(True):
    if (s % 50 != x % 50):
        s+=1
        continue
    ok = False
    i = (s // 50) % 475
    for j in range(25):
        i = (i*96 + 42) % 475
        if (i + 26 == p):
            ok = True
            break
    if (ok):
        print((max(0, s-x) + 50) //100)
        break
    # print(s)
    s+=1
