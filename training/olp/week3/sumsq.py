t = int(input())
while(t):
    t-=1
    n = int(input())
    a = n//2
    b = n//2
    if (n % 2 == 1): 
        b+=1
    # print(a, b)
    even = 2*a*(a+1)*(2*a+1)//3
    odd = b * (2*b+1) *(2*b-1)//3
    # print(even, odd)
    print(even - odd)
