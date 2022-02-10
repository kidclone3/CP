n = int(input())
taka = 0
aoki = 0
for i in range(n):
 a, b = map(int, input().split())
 if (taka <= a and aoki <= b):
    taka = a
    aoki = b
 elif taka <= a and aoki > b:
    tmp = (aoki-1)//b + 1
    taka = a*tmp
    aoki = b*tmp
 elif taka > a and aoki <= b:
    tmp = (taka-1)//a + 1
    taka = a*tmp
    aoki = b*tmp
 elif taka >= a and aoki >= b:
    t1 = (taka-1)//a + 1
    t2 = (aoki-1)//b + 1
    # tmp = max(tmp1, tmp2)
    if (t1 * a >= taka and t1 * b >= aoki and t2 *a >= taka and t2 * b >= aoki):
        if (t1*(a+b) <= t2*(a+b)):
            taka = t1*a
            aoki = t1*b
        else:
            taka = t2*a
            aoki = t2*b
    elif (t1*a >= taka and t1*b >= aoki):
            taka = t1*a
            aoki = t1*b
    else:
            taka = t2*a
            aoki = t2*b

print(taka + aoki)
