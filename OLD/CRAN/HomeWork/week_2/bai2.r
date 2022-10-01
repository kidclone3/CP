# Nhap ma tran
a = c(1,3,5,-1)
b = c(7, 3, 3, 7)

# Bien mang thanh ma tran
a = matrix(a, nrow = 2, ncol = 2)
b = matrix(b, nrow = 2, ncol = 2)
a = t(a)
b = t(b)

# Tim nghich dao cua A
x = matrix(0,nrow = 2, ncol = 2)
x = solve(a)

# Tim C.
c = x %*% b
print(c)
