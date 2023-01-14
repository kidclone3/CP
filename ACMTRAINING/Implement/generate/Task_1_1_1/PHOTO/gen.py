import random
from utils import *


filename = "PHOTO"
max_n = 1000
max_n_2 = 1000000
max_N = int(1e9)

compile(filename=filename)
create(filename=filename)

for num in range(1, 11):
    with open(input(filename=filename, number=num), "w+") as f:
        n = random.randint(1, max_n)
        d = random.randint(1, max_N)
        
        print(n, d, file=f)
        for i in range(n):
            x = random.randint(1, max_n)
            y = random.randint(1, max_n)
            print(x, y, file=f)
    run(filename=filename, number=num)
for num in range(11, 51):
    with open(input(filename=filename, number=num), "w+") as f:
        n = random.randint(1, max_n_2)
        d = random.randint(1, max_n_2)
        
        print(n, d, file=f)
        for i in range(n):
            x = random.randint(1, max_n)
            y = random.randint(1, max_n)
            print(x, y, file=f)
    run(filename=filename, number=num)


