def find_2(x):
    cnt = 0
    while(x % 2 == 0 and x > 0):
        cnt+=1
        x//=2
    return cnt
for i in range(2, 101, 2):
    print(i, end = ", ")
print()
for i in range(2, 101, 2):
    print(find_2(i), end = ", ")