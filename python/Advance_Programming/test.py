a = input().split()
dicts = {}
for x in a:
    if (x not in dicts.items()):
        dicts[x] = 1
    else:
        dicts[x] += 1
print(dicts)