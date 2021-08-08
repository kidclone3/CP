a, b, x = map(int, input().split())
if (a%x != 0):
    a = a+x - a%x
b -= b%x
print(max(0, (b-a)//x + 1))