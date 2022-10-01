start = 1100
end = 9090
s = '; '.join([str(i) for i in range(start, end+1, 11) if i % 3 != 0])
print(s)
    