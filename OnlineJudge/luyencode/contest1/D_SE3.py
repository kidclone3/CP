n = int(input())
def solve(n):
    tmp = 3
    ans = 1
    while(ans <= 1000):
        if (tmp % n == 0):
            return ans;
        tmp*=10
        tmp+=3
        ans+=1
    return -1

print(solve(n))