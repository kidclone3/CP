
dictionary = {}
for i in input().split():
    dictionary[i] = int(i, base = 2)
# print(dictionary)
print([key for key, value in dictionary.items() if value % 5 == 0])
