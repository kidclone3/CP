import random
from utils import *

filename = "hsgTpHN2018B2"
compile(filename)
create(filename)

max_test = 50
max_n_1 = 1000
max_n_2 = 1000000
max_n_3 = int(1e9)
for num in range(1, 11):
    # with open(input(filename, num), "w+") as f:
    #     n = random.randint(1, max_n_1)
    #     print(n, file=f)
    #     for i in range(n):
    #         print(random.randint(1, max_n_2), file=f, end=" ")
    #     print(file=f)
    run(filename=filename, number=num)

for num in range(11, 51):
    # with open(input(filename, num), "w+") as f:
    #     n = random.randint(1, max_n_2)
    #     print(n, file=f)
    #     for i in range(n):
    #         print(random.randint(1, max_n_3), file=f, end=" ")
    #     print(file=f)
    run(filename=filename, number=num)