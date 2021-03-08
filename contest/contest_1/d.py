n = int(input())
ans = 0
if (n<=6):
    # print(1)
    ans = 1
else:
    if (n<=11):
        ans = 2
    else:
        if (n%11 == 0):
            ans = n//11 * 2
        else:
            if (n%11 <=6):
                ans = n//11 * 2 + 1
            else:
                ans = n//11 * 2 + 2
print(ans)