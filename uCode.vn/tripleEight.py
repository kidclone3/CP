def check(n):
    if (n<888):
        return False
    s = 0
    counter = 3
    while(counter > 0):
        counter-=1
        s*=10
        s+=n%10
        n/=10
    if (s==888):
        return True
    return False
t = int(input()) 
while (t>0):
    t-=1
    x = int(input())
    x+=1
    while (check(x**3) == False):
        x+=1
    print(x)