s = input()
def palin(s):
    n = len(s)
    if (s == s[::-1]):
        return "YES"
    s3 = ""
    for i in range(0, n, 2):
        s3 += s[i]
    if (s3 == s3[::-1]):
        return "YES"
    return "NO"

print(palin(s))