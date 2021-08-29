w, a, b = [int(i) for i in input().split()]
if (b<=a+w<=b+w or a<=b<=a+w):
    print(0)
    exit()
print(min(abs(b-(a+w)), abs(b+w-a)))