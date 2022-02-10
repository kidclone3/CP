s = input()
ed = len(s) - 2
# print(s[0:7] == s[7:14])
while(ed > 0):
    if (ed % 2 == 0):
        if (s[0:ed//2] == s[ed//2 : ed]):
            print(ed)
            break
    ed -= 1
    # print(ed)