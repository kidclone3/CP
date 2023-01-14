n = int(input())
def sum_digit(x):
    return sum([int(i) for i in str(x)])
print(1) if n % (sum_digit(n)) == 0 else print(0)