def maxProduct(a):
    m = int(1e9+7)
    mx = int(-1e18)
    tich1 = 1
    tich2 = 1
    am1 = 0
    am2 = 0

    for i in range(len(a)):
        tich2 = ((tich2 + m) % m * (a[i] + m) % m) % m
        if (a[i] < 0):
            am2 += 1
        if am2 % 2 == 1:
            tich2 -= m 
        # print(tich2)
    
    for i in range(len(a)-1):
        # if tich1 * a[i] < 0:
        #     tich1 = ((tich1 + m) % m * (a[i] + m) % m) % m
        #     tich1 -= m
        # else:
        if a[i] < 0:
            am1 += 1
        tich1 = ((tich1 + m) % m * (a[i] + m) % m) % m
        if (am1 % 2 == 1):
            tich1 -= m

        # if tich2 * a[i] < 0:
        #     tich2 = (tich2 + m) % m * pow(a[i] + m, m-2, m) % m
        #     tich2 -= m
        # else:
        if a[i] < 0:
            am2 -= 1
        tich2 = (tich2 + m) % m * pow(a[i] + m, m-2, m) % m
        if am2 % 2 == 1:
            tich2 -= m

        tmp1 = min(tich1, tich2)
        tmp2 = max(tich1, tich2)
        if (tmp1 * tmp2 > 0 and tmp1 < 0) or tmp1 < -tmp2:
            mx = max(mx, (tmp1 + tmp2) % m - m)
        else:
            mx = max(mx, (tich1 + tich2) % m)
        # if (tich1 * tich2 > 0 and tich1 < 0):
        #     mx = max(mx, (tich1 + tich2) % m - m)
        # else:
        #     mx = max(mx, (tich1 + tich2) % m)
        
        # print(tich1, tich2)
        # print(mx)
    return mx

a = [-3,-2,-2,7,3]
# for i in range(0, int(1e4)):
#     a.append(int(1e4))
print(maxProduct(a))