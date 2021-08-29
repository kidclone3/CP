a, b, c = map(int, input().split())
def solve():
	tmp = a
	while(tmp < int(1e6)):
		if (tmp % b) == (c % b):
			return "YES"
		tmp += a
	return "NO"
print(solve())
