# a = 11 
# b = 123 
# print(sum(a^(b<<i) for i in range(1, 10)) % 127)
def xorAndSum(a, b):
    a = int(a, 2)
    b = int(b, 2)
    mod = int(1e9+7)
    return (sum(a^(b << i) for i in range(0, 314159+1)) % mod)
a = input()
b = input()
print(xorAndSum(a, b))
