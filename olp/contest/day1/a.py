n = int(input())
le = 0
chan = 0
if (n % 2 == 0):
    chan = (n+2)*((n-2)//2+1)//2
    le = (n)*((n-2)//2+1)//2
else:
    le = (n+1)*((n-1)//2+1)//2
    chan = (n+1)*((n-3)//2+1)//2
# print(le, chan)
print(-le+chan)