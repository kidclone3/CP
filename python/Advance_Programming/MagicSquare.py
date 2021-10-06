def isMagicSquare(m):
    n = len(m)
    # Sum of each row, col
    row = [0] * n
    col = [0] * n

    # Sum of diagonal left + right
    diag_left = 0
    diag_right = 0

    for i in range(n):
        for j in range(n):
            row[i] += m[i][j]
            col[j] += m[i][j]
            if (i == j):
                diag_left += m[i][j]
            if (j == n-i-1):
                diag_right += m[i][j]
    if (diag_left != diag_right):
        return False
    row = [i - diag_left for i in row]
    col = [i - diag_left for i in col]
    for i in range(n):
        if row[i] != 0 or col[i] != 0:
            return False
    return True
    

def inputMatrix():
    m = []
    while(True):
        inp = input()
        if (inp == ''):
            break
        tmp = [int(i) for i in inp.split()]
        m.append(tmp)
    return m

# t = int(input())
# while(t > 0):
#     m = inputMatrix()
#     print(isMagicSquare(m))
#     t-=1
