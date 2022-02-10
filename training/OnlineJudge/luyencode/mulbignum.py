def ppow(a, b):
    ans = 1
    while(b>0):
        ans*=a
        b-=1
    return ans
a, b = input().split()
a = int(a)
b = int(b)
print(a**b - b**a)
# print(ppow(a,b) - ppow(b, a))