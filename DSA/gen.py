import random


def generate(n, q, dir):
    srcFile = open(dir, "w")
    print(n, file=srcFile)
    for i in range(n):
        print(random.randint(1, n), end=" ", file=srcFile)
    print(file=srcFile)
    q = int(1e5)
    print(q, file=srcFile)
    for i in range(q):
        # print(random)
        a = random.randint(1, n)
        b = random.randint(1, n)
        if b < a:
            a, b = b, a
        print(a, b, end="\n", file=srcFile)


# N = int(1e5)
# generate(N, N, "input.txt")

# first, generate 1000 test with N = 1e3
#for i in range(int(1e3)):
#    generate(int(1e3), int(1e3), f"data/1e3_{i}.txt")
# second, generate 1000 test with N = 1e5
for i in range(int(1e5)):
    generate(int(1e5), int(1e5), f"data/1e5_{i}.txt")
