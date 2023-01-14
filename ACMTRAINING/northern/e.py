import sys 
sys.setrecursionlimit(15000)
def fun(u,v) -> int:
    if(u>v):
        return 2*fun(u-v,v)+2
    if(u<v):
        return 2*fun(u,v-u)+1
    return 0
while True:
    try:
        s = input()
    except EOFError:
        break
    u, v = map(int, s.split())
    print(fun(u, v))

