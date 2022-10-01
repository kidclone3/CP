n = int(input())
inStr = input().split()
dictionary = {}
for i in inStr:
    dictionary[i] = i + i[::-1]
print(dictionary)