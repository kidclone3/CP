from math import *
import bisect
# N = int(55)
# check = [False]* N
# big = []
# for i in range(2, int(sqrt(N))+1):
#     if (~check[i]):
#         for j in range(2*i, N, i):
#             check[j] = True
# for i in range(2, N):
#     if check[i] == False:
#         if len(big) == 0:
#             big.append(i)
#         else:
#             big.append(big[-1]*i)

# print(*big, sep=", ")

big = [2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230, 200560490130, 7420738134810, 304250263527210, 13082761331670030, 614889782588491410, 32589158477190044730]
t = int(input())
while(t):
    t-=1
    n = int(input())
    if n < 2:
        print(0)
    else:
        a = bisect.bisect_left(big, n, 0, len(big))
        if big[a] > n: a-=1
        print(a+1)
