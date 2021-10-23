hexa = input().strip().upper().split('.')

ans = int(hexa[0], 16) * 1.0

hexch2int = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10 , 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
if (len(hexa) == 2):
    base = 1/16
    tmp = 0
    for i in range(0, len(hexa[1])):
        tmp += hexch2int[hexa[1][i]] * base
        base /= 16
    ans += tmp

print(ans)


