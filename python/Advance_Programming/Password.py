def checkPassword(s):
    s = str(s)
    num, upper, lower, char = True, True, True, True
    if (len(s) < 8):
        return False
        
    for i in s:
        if i.isupper() and upper:
            upper = False
        if i.islower() and lower:
            lower = False
        if i.isdigit() and num:
            num = False
        if i in '~!@#$%^&*'and char:
            char = False
        
    return not(num or upper or lower or char)
    
s = '12345678'
print(checkPassword(s))
    