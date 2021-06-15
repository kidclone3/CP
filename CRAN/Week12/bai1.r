setwd("/home/delus/Documents/mycodes/CRAN/Week12")
input = read.csv("dulieu2.csv", header = T)
input = na.omit(input)
summary(input)
# x = input[, 5]
remove_outline <- function(x) {
  ans = x
  q = quantile(x, c(0.25, 0.75))
  H = 1.5 * IQR(x)
  ans[x < (q[1] - H)] = NA
  ans[x > (q[2] + H)] = NA
  return(ans)
}
data.cleaned = remove_outline(input[, 5])

boxplot(input[, 5], horizontal = T)

boxplot(data.cleaned, xlab = "Chieu ngang", ylab = "Chieu doc", horizontal = T)
warnings()
# remove_outline(input[, 4])
