t = int(input())
def solve():
    u = [0]*10
    for i in range(1, 8):
        u[i] = int(input())
       
    x = u[1]+u[2]+u[3]-u[4]-u[5]-u[6]+u[7]
    for i in range(4, 7):
        u[i] -= u[7]
    u[1] -= u[5]+u[6]+u[7]
    u[2] -= u[4]+u[5]+u[7]
    u[3] -= u[4]+u[6]+u[7]
    for i in range(1, 8):
        if u[i] < 0:
            return -1
    return x
while (t):
    t -= 1
    print(solve())