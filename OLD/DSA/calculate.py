def calculate(dir, type):
    ans = 0
    with open(f"{dir}/{type}.txt", "r") as f:
        for i in range(1000):
            ans = ans + int(f.readline())
    return ans


print("Get answer of 1e3 tests first")
print("Fenwick Tree time = ", calculate("cerr/fenwick", "1e3"))
print("Fast Segment Tree time = ", calculate("cerr/fast_st", "1e3"))
print("Slow Segment Tree time = ", calculate("cerr/slow_st", "1e3"))

print("\nGet answer of 1e5 tests")

print("Fenwick Tree time = ", calculate("cerr/fenwick", "1e5"))
print("Fast Segment Tree time = ", calculate("cerr/fast_st", "1e5"))
print("Slow Segment Tree time = ", calculate("cerr/slow_st", "1e5"))
