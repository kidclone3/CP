f = lambda x : x**4 + 2*(x**3) - x - 1
# Dung vong for de tim khoang nghiem
for i in range(-10, 10):
    print(i, f(i))

# Sau khi dung for, ta tim ra 2 vi tri nghiem doi dau. [-2, -1] va [0,1]
# tien hanh phuong phap chia doi.
left = -2
right = -1
e = 0.001
while right - left > e:
    mid = (left + right) / 2
    if f(left)*f(mid) < 0:
        right = mid
    else:
        left = mid
print(left)