def reverse(x) -> int:
    result = 0
    while (x > 0):
        result *= 10
        result += x%10
        x //= 10
    return result
n = int(input())
a = map(int, input().split())
dictionary = {}
for i in a:
    dictionary[i] = reverse(i*i)
print(dictionary)
    