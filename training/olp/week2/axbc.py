def solve(a: int, b: int, c: int):

    if a == 0: 
        if b == 0:
            return 0
        elif b == 1 or c == 0:
            return 'oo'
        elif c != 0:
            return 0
    if a != 0:
        if c == 0: 
            return 'oo'
        elif c % 2 != 0: 
            if (1 - b)%a == 0 :
                return 1
            else:
                return 0
        else:
            count = 0
            if (1-b)%a == 0:
                count+=1
            if (-1-b)%a == 0:
                count+=1
            return count

q = int(input())
for i in range(q):
    a, b, c = [int(x) for x in input().split()]
    print(solve(a,b,c))