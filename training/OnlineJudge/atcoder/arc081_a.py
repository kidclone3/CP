n = int(input())
a = [int(i) for i in input().split()]
a.sort(reverse = True)
# print(a)
h,w = 0, 0
# print(h, w)
i = 0
while(i < n-1):
    # print(i)
    if (a[i] == a[i+1]):
        if (h == 0):
            h = a[i]
            i+=1
        elif (w == 0):
            w = a[i]
            # print(i)
            break
    i+=1
# print(h, w)
print(h*w)