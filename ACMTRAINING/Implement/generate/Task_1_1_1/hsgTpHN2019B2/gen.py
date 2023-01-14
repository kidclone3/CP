import os 
import sys
import random

    # os.system("g++-11 -std=c++20 hsgTpHN2019B2.cpp -o a -Wshadow -Wall -O2 -Wno-unused-result")
from utils import *

filename = "hsgTpHN2019B2"
compile(filename)
create(filename=filename)

num_test = 50
max_n_1 = 100
max_n_2 = 1000
max_n_3 = 10000
max_N = int(1e9)
# for i in range(1, 11):
#     with open(input(filename=filename, number=i), "w+") as f:
#         n = random.randint(1, max_n_1)
#         m = random.randint(1, max_n_1)
#         print(m, n, file = f)
#         arr = [0]*m
#         for j in range(m):
#             arr[j] = random.randint(1, max_n_1)
#         print(*arr, file = f)
#         for j in range(n):
#             l = random.randint(1, m-1)
#             r = random.randint(l+1, m)
#             x = random.randint(1, max_n_1)
#             print(l, r, x, file = f)
#     run(filename=filename, number=i)
# for i in range(11, 51):
#     with open(input(filename=filename, number=i), "w+") as f:
#         n = random.randint(1, max_n_2)
#         m = random.randint(1, max_n_2)
#         print(m, n, file = f)
#         arr = [0]*m
#         for j in range(m):
#             arr[j] = random.randint(1, max_n_2)
#         print(*arr, file = f)
#         for j in range(n):
#             l = random.randint(1, m-1)
#             r = random.randint(l+1, m)
#             x = random.randint(1, max_n_2)
#             print(l, r, x, file = f)
#     run(filename=filename, number=i)
for i in range(51, 101):
    with open(input(filename=filename, number=i), "w+") as f:
        n = random.randint(1, max_n_3)
        m = random.randint(1, max_n_3)
        print(m, n, file = f)
        arr = [0]*m
        for j in range(m):
            arr[j] = random.randint(1, max_N)
        print(*arr, file = f)
        for j in range(n):
            l = random.randint(1, m-1)
            r = random.randint(l+1, m)
            x = random.randint(1, max_N)
            print(l, r, x, file = f)
    run(filename=filename, number=i)