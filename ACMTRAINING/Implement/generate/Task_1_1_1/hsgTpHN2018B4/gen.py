import random
from utils import *


filename = "hsgTpHN2018B4"
max_n = 1000
# max_N = int(1e3)

compile(filename=filename)
create(filename=filename)

for num in range(1, 51):
    # with open(input(filename=filename, number=num), "w+") as f:
    #     n = random.randint(1, max_n)
    #     m = random.randint(1, max_n)
    #     k = random.randint(1, n*m)
        
    #     print(n, m, k, file=f)
    #     for i in range(n):
    #         for j in range(n):
    #             x = random.randint(1, max_n)
    #             print(x, file=f, end = " ")
    #         print(file=f)
    run(filename=filename, number=num)


