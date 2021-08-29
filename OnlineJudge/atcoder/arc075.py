n = int(input())
a = []
sum = 0
for i in range(n):
    tmp = int(input())
    a.append(tmp)
    sum += tmp
def solve(sum):
    if (sum % 10 != 0):
        return(sum)
    else:
        a.sort()   
        for i in range(n):
            if (a[i] % 10 != 0):
                sum -= a[i]
                return(sum)
        return 0
print(solve(sum))