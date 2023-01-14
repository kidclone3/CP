n = int(input())
a = [int(i) for i in input().split()]
four = 0
even = 0
odd = 0
for i in a:
    if i % 4 == 0: 
        four += 1
    elif i % 2 == 0:
        even += 1
    else:
        odd += 1
if even % 2 == 1:
    even -= 1
    odd += 1
if odd - four > 1:
    print("No")
else:
    print("Yes")