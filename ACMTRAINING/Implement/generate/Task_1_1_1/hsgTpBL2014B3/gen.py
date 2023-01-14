import random
from utils import *


filename = "hsgTpBL2014B3"
max_n = 100
max_N = 100

compile(filename=filename)
create(filename=filename)

for num in range(1, 51):
    with open(input(filename=filename, number=num), "w+") as f:
        n = random.randint(1, max_n)
        print(n, file=f)
        for i in range(n):
            for j in range(n):
                x = random.randint(1, max_N)
                print(x, file=f, end = " ")
        print(file=f)
    run(filename=filename, number=num)


