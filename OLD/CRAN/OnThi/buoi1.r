# bai 1
# nhap du lieu
pr = c(9000, 9500, 9400, 9400, 10000, 9500, 10300, 10200)
# tinh tbc
avg = mean(pr)
print(avg > 9500)
#dem so cua hang ban dat hon Edmund
count = sum(pr > 9500)
print(count)

# bai 2 
a = c(1, 5, 3, -1)
a = matrix(a, nrow = 2)

b = c(7, 3, 3, 7)
b = matrix(b, nrow = 2)

# tinh ma tran c sao cho A*C = B ==> C la nghiem cua A va B
C = solve(a, b)
C

# bai 3
days = c(17, 16, 20, 24, 22, 15, 21, 15, 17, 22)
print(min(days))
print(max(days))
print(mean(days))

# sua ngay co gia tri = 24
days[days == 24] = 18
days      
print("So ban di lam nhieu hon 20p la")
print(sum(days >= 20))

# so ban di lam it hon 17p:
print(sum(days <= 17)/sum(days>0))

# bai 4
bill = c(46, 33, 39, 37, 46, 30, 48, 32, 49, 35, 30, 48)
sum_bill = sum(bill)
sum_bill
cat(sum(bill > 40) / length(bill) * 100, "%")

      