while(True):
    try:
        a = [int(i) for i in input().split()]
        print(a)
    except EOFError:
        break
