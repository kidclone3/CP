import random
from utils import *


filename = "BALES"
max_n = 10000
# max_N = int(1e3)

compile(filename=filename)
create(filename=filename)

for num in range(1, 51):
    with open(input(filename=filename, number=num), "w+") as f:
        n = random.randint(1, max_n)
        
        print(n, file=f)
        for i in range(n):
            x = random.randint(1, n)
            print(x, file=f, end = " ")
        print(file=f)
    run(filename=filename, number=num)


