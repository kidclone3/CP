s = input()
mp = [0]*40
for i in s:
    mp[ord(i)-ord('a')]+=1

for i in range(ord('z')-ord('a')+1):
    if (mp[i] == 0):
        print(chr(ord('a')+i))
        exit()
print("None")