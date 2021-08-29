k, s = map(int, input().split())
ans = 0
for i in range(0, k+1):
	if i > s or (s-i) > 2*k:
		pass
	else:
		if 0 <= s-i <= k:
			ans += s-i + 1
			# print(ans)
		else:
			ans += k -(s-i-k) + 1
			# print(ans)
print(ans)
