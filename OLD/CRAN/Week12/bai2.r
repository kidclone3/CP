setwd("/home/delus/Documents/mycodes/CRAN/Week12")
data = read.csv("dulieu2.csv", header = T)
data = na.omit(data)

# 6)
plot(data$Profit, data$COGS / 10, xlab = "Loi nhuan", ylab = "Gia von")

# 7)
boxplot(data$Profit, xlab = "Chieu ngang", ylab = "Chieu doc", horizontal = T)
title("Bieu do loi nhuan")

# 8)
boxplot(data$Discounts, xlab = "Chieu ngang", ylab = "Chieu doc", horizontal = T)
title("Bieu do loi nhuan theo muc do chiet khau")

# 9)
three_q = function(x) {
  ans = x
  q = quantile(x, c(0.25, 0.75))
  H = IQR(x)
  ans[x < q[1] - 3 * H | x > q[2] - 3 * H] = NA
  # ans[x > q[2] - 3 * H] = NA
  return(ans)
}

three_sigma = function(a) {
  ans = subset(a, mean(a) - 3*sd(a) < a & a < mean(a) + 3 * sd(a))
  return(ans)
}
a = data$Profit
data.remove = three_q(data$Profit)

boxplot(data.remove, xlab = "Chieu ngang", ylab = "Chieu doc", horizontal = T)

tmp = three_sigma(data$Profit)
boxplot(tmp, horizontal = T)
