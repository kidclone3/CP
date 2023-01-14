from collections import defaultdict
t = int(input())
while t:
    t-=1 
    n = int(input())
    a = [int(_) for _ in input().split()]
    mp = defaultdict(int)
    for i in a:
        mp[i] += 1 
    a = sorted(list(mp.values()), reverse= True)
    # print(a)
    if len(a) == 1 or a[0] != a[1]:
        print("YES")
    else: 
        print("NO")
