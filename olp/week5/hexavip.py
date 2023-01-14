t = int(input())
while (t):
    t -= 1
    a, b, c = map(int, input().split())
    print((b+a-1)*(c+a-1) - a*(a-1))