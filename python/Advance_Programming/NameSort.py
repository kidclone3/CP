# -*- coding: utf-8 -*-
import locale

locale.setlocale(locale.LC_ALL, 'vi_VN')

def inputList():
    names = []
    while(True):
        inp = input()
        if (inp == ''):
            break
        names.append(inp)
    return names
    
def getName(s):
    lname = ''
    fname = ''
    token = s.strip().split(' ')
    if (len(token) == 1):
        fname = token[0]
    else:
        fname = token[-1]
        for i in range(len(token)-1):
            lname = lname + token[i] + ' '
        lname = lname.strip()
    # lname = token[2]
    # fname = token[1]
    # print(len(token))
    return lname, fname

def compare(name):
    lname, fname = getName(name)
    return locale.strxfrm(fname), locale.strxfrm(lname)
def sortNamesList(names):
    names.sort(key = compare)
    return names

# names = inputList()
# names = sortNamesList(names)
# print(names, end='\n')
