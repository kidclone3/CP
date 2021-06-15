# a)
mucthunhap = c(rep(2.6, 5), rep(2.8, 8), rep(3.0, 10), rep(3.2, 9), rep(3.4,14))
plot(table(mucthunhap))
# b)
GT_trungbinh = mean(mucthunhap)
phuong_sai = var(mucthunhap)

ans = 0
for (i in mucthunhap) {
  ans = ans + (i - GT_trungbinh) * (i - GT_trungbinh);
}
ans = ans / (46 - 1)
ans

# c)
u0 = 3.22

T = (GT_trungbinh - u0) * sqrt(length(mucthunhap)) / sqrt(phuong_sai)
print(T)

print(abs(T) >= 1.96)
