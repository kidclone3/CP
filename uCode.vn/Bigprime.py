# Using Miller algorithm 
# https://vietcodes.github.io/algo/miller
a = [2, 3, 5, 7, 11, 13, 17, 19, 23]
def miller(s, d, n, a):
    if (n==a):
        return True
    p = (a ** d) % n;
    while (s>=0):
        if (p == n-1 or p == 1):
            return True
        p = p * p%n
    return False
def factorize(n):
    s = 0
    while (n%2==0):
        n/=2
        s += 1 
    return {s, n}
def check_n(n):
    if (n%2 == 0):
        return False
    s, d = factorize(n-1)
    for x in a:
        if (n<x):
            break
        if (miller(s, d, n, x) == False):
            return False
    return True
def solve(n):
    if (n%2 == 1):
        while (True):
            n+=2;
            s, d = factorize(n-1)                
            for i in a:
                if (n<a):
                    break
                if (miller(s, d, n, i) == False):
                    break
            return n
    else:
        while (True):
            n+=1;
            s, d = factorize(n-1)                
            for i in a:
                if (n<i):
                    break
                if (miller(s, d, n, i) == False):
                    break
            return n
n = int(input())
# Kiem tra xem n co' phai so nguyen to ko
if (check_n(n)):
    print(n)
    exit()
print(solve(n))