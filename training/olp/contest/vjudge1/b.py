from collections import defaultdict
t = int(input())
while t:
    t -= 1 
    n = int(input())
    a = [int(i) for i in input().split()]
    mp = defaultdict(int) 
    mx = -1;
    for i in a:
        mp[i]+=1 
        mx = max(mx, mp[i])

    print(n - mx) 
