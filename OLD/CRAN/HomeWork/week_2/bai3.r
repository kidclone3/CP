day = c(17,16,20,24,22,15,21,15,17,22)
# a) 
print(min(day))
print(mean(day))
print(max(day))

# b) Thay the so 24 = 18
day[day==24] = 18

# c)
# 1. So ban di lam >20p
print(sum(day>20))
# 2. Phan tram nhung ban di lam <=17p
cat(c(sum(day<=17)/length(day) * 100, "%", "\n"), sep="")

