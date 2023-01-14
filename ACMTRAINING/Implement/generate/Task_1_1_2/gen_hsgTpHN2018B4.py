import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent.parent))
from utils import *
from conf import *

filename = "hsgTpHN2018B4"

num_tests = 50
max_n = 1000
max_N_1 = int(1e6)
max_N_2 = int(1e9)

compile_cpp(filename=filename)
create(filename)

# part 1
for i in range(start_part_1, end_part_1):
    with open(input(filename=filename, number=i), "w+") as f:
        n = random.randint(1, max_n)
        m = random.randint(1, max_n)
        k = random.randint(1, n*10)
        print(m, n, k, file = f)
        tmp = set()
        for row in range(m):
            for col in range(n):
                x = random.randint(1, max_N_1)
                print(x, end = " ", file=f)
                tmp.add(x)
            print(file=f)
        print(k, len(tmp))
        assert (len(tmp) >= k), len(tmp)
    run(filename=filename, number=i)

# for i in range(start_part_2, end_part_2):
#     with open(input(filename=filename, number=i), "w+") as f:
#         n = random.randint(1, max_n)
#         m = random.randint(1, max_n)
#         k = random.randint(1, n*10)
#         print(m, n, k, file = f)
#         tmp = set()
#         for row in range(m):
#             for col in range(n):
#                 x = random.randint(1, max_N_2)
#                 print(x, end = " ", file=f)
#                 tmp.add(x)
#             print(file=f)
#         print(k, len(tmp))
#         assert (len(tmp) >= k), len(tmp)
#     run(filename=filename, number=i)

