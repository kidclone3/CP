def check(x:list):
    ans = ''
    for i in x:
        ans += str(i)
    return ans
lst = [1, 2]
tmp = ','.join([check([x]) for x in lst])
tmp = '{' + tmp + '}'
print(tmp)