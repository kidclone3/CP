a1 = int(input())
a2 = int(input())
b1 = int(input())
b2 = int(input())
ans = [max(a1+b1,max(a2, b2)), max(a2+b1, max(b2, a1)), max(a1+b2,max(a2, b1)), max(a2+b2,max(a1, b1))]
print(min(ans)**2)
