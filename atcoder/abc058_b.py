o = input()
e = input()
i = 0
j = 0
while True:
    if (i == len(o) and j < len(e)):
        print(e[j], end="")
        j+=1
    elif (i < len(o) and j == len(e)):
        print(o[i], end="")
        i+=1
    elif (i < len(o) and j < len(e)):
        print(f"{o[i]}{e[j]}", end="")
        i+=1
        j+=1
    else:
        break
