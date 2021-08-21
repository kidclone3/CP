n = int(input())
a = [int(i) for i in input().split()]
# min
ck = [0]*8
mn = 0
mx = 0
for i in a:
    if (i >= 3200):
        mx += 1
    else:
        for j in range(0, 8):
            if (i < 400*(j+1)):
                ck[j] = 1
                break
for i in ck:
    mn += i
if (mn == 0):
    print(f"1 {mn + mx}")    
else:
    print(f"{mn} {mn + mx}")