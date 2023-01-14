import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent.parent))
from utils import *
from conf import *

filename = "PHOTO"

num_tests = 50
max_n = 10000
max_N_1 = int(1e4)
max_N_2 = int(1e6)

def generate_test(max_n, max_N, filename):
    with open(input(filename=filename, number=i), "w+") as f:
        n = random.randint(1, max_n)
        d = random.randint(1, max_N*100)
        a = random.randint(1, max_n)
        b = random.randint(1, max_n)
        print(n, file = f)
        print(d, file = f)
        print(a, b, file = f)
        for col in range(n):
            x = random.randint(1, max_N//100)
            y = random.randint(1, max_N//100)
            print(x, y, file=f)
    
compile_cpp(filename=filename)
create(filename)

# part 1
for i in range(start_part_1, end_part_1):
    generate_test(max_n=max_n, max_N=max_N_1, filename=filename)
    run(filename=filename, number=i)

for i in range(start_part_2, end_part_2):
    generate_test(max_n=max_n, max_N=max_N_2, filename=filename)
    run(filename=filename, number=i)

