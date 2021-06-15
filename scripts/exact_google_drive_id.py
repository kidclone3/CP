import re
def exact():
    inp = input()
    ans=""
    for i in range(0, len(inp)):
        if (inp[i] == '='):
            for j in range(i+1, len(inp)):
                if (inp[j] == '&'):
                    ans=inp[i+1:j]
                    return ans

    return ans

n = 5
for i in range(n):
    print(exact())
