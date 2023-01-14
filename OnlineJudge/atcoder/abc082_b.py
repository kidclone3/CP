s = input()
t = input()
s_tmp = sorted(s)
s = "".join(s_tmp)
t_tmp = sorted(t, reverse=True)
t = "".join(t_tmp)
# print(s, t, sep= " ")
def cmp(s, t):
    while(len(s) < len(t)):
            s = s + "$"
    while(len(s) > len(t)):
            t = t + "$"
    for i in range(0, len(s)):
            if (s[i] < t[i]):
                return True
            elif (s[i] > t[i]):
                return False
    return False

if (cmp(s, t)):
    print("Yes")
else:
    print("No")