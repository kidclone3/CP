# 1)
setwd("/home/delus/Documents/mycodes/CRAN/Week10/")
data = read.csv("dulieu2.csv", header = T)
data = na.omit(data, "None")

# 2)
pie(table(data$Country), 
    main = "Bieu do qua the hien luong hang hoa o cac quoc gia",
    col = 1:5
)
legend(1.1, 1.1, c("Canada", "France", "Germany", "Mexico", "United States of America"), col = 1:5, pch = 17)
table(data$Country)

# 3)
counts = table(data$Discount.Band, data$Product)
barplot(counts, 
        beside = T,
        main = "Muc do giam gia cua tung san pham", 
        xlab = "So luong san pham",
        ylab = "Ten san pham",
        ylim = c(0, 70),
        col = c("red", "blue", "pink", "yellow"),
)
legend(2, 69, 
       pch = 15,
       c("High", "Low", "Medium", "None"),
       col = c("red", "blue", "pink", "yellow"),     
)
# 4)
paseo = data[data$Country == "Germany" & data$Product == "Paseo", ]
paseo_month = table(paseo$Month.Number)
paseo_month

barplot(paseo_month,
        main = "Cac mat hang Paseo duoc ban tai nuoc Duc trong 12 thang",
        xlab = "Thang",
        ylab = "So luong"
)

# 5)
plot(data$Profit / 10^5, data$COGS / 100, 
    main = "Bieu do tan xa"
)

# 6)
hist(data$Profit,
     main = "Histogram cho loi nhuan",
     xlab = "Loi nhuan",
     ylab = "Tan so",
     probability = T
)
polygon(density(data$Profit), border = "Red")
