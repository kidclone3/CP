import numpy

n, m = map(int, input().split())

arr1 = []
for i in range(n):
    tmp = [int(j) for j in input().split()]
    arr1.append(tmp)
arr1 = numpy.asarray(arr1)

arr2 = []
for i in range(n):
    tmp = [int(j) for j in input().split()]
    arr2.append(tmp)
arr2 = numpy.asarray(arr2)

print(arr1 + arr2)
print(arr1 - arr2)
print(arr1 * arr2)
print(arr1 // arr2)
print(arr1 % arr2)
print(arr1 ** arr2)

