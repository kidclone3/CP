n=int(input())
# ans = 0
if (n<=6):
    ans = 1
elif n <= 11:
    ans = 2
elif n%11 == 0:
    ans = n//11 * 2
elif n % 11 <= 6:
    ans = n//11 * 2 + 1
else:
    ans = n//11 * 2 + 2
print(ans)
