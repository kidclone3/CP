mul = 1
MOD = 1000000000+7
arr = [120943, 32423, 234, 234234, 23, 123]
for i in arr: 
    mul *= i
# print (mul) 
print (mul % MOD, end="")
