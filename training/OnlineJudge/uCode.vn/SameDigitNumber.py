from itertools import permutations

def split(n):
    return [char for char in n]
def combine(x):
    sum = 0
    # print(len(x))
    for i in range (len(x)):
        # print(x[i])
        sum *= 10
        # sum += ord(i) - ord('0')
        sum += int(x[i])
    return sum
n = input()

perm = permutations(split(n))
tmp = []
for i in list(perm):
    tmp.append(i)
ans = []
for i in tmp:
    ans.append(combine(i))
ans.sort
for i in ans:
    if (i>int(n)):
        print(i)
        exit()
print(-1)