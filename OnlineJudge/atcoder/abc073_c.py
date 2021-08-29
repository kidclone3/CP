n = int(input())
mp = {}
for i in range(n):
    tmp = int(input())
    if tmp in mp.keys():
        del mp[tmp]
    else:
        mp[tmp] = 1
print(len(mp))