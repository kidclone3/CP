mp = dict()
s = input()
for i in s:
    if i not in mp.keys():
        mp[i] = 1
    else:
        mp[i] += 1
mx = 0
ch = 'a'
for i in s:
    if (mp[i] > mx):
        mx = mp[i]
        ch = i
print(ch, mx)