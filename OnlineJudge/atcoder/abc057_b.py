n, m = map(int, input().split())
student = []
checkpoint = []
for i in range(n):
	a, b = map(int, input().split())
	student.append((a, b))
for i in range(m):
	a, b = map(int, input().split())
	checkpoint.append((a, b))
for i in student:
	ans = int(1e18)
	idx = 0
	for j in range(m):
		tmp = abs(i[0] - checkpoint[j][0]) + abs(i[1] - checkpoint[j][1])
		if ans > tmp:
			ans = tmp
			idx = j
	print(idx+1)
