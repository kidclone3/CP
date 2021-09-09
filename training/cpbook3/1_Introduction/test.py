n = int(input())
for i in range(n):
    mx = max([int(j) for j in input().split()])
    
    print(f"Case {i+1}: {mx}")
