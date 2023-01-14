n = int(input())
# odd = 1 + 3 + 5 +... 3n (+1)
# even = -2 - 4 - 6... = - (2 + 4 + 6 + ... 3n (+1))
end_even = 3 * n
end_odd = 3 * n

if (n & 1):
    end_even = 3*n+1
else:
    end_odd = 3*n + 1

odd = (1 + end_odd) * ((end_odd - 1)//2+1)//2
even = (2 + end_even) * ((end_even - 1)//2+1)//2

print(odd - even)
