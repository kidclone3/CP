#a.
setwd("/home/delus/Documents/code/CRAN/HomeWork/week_5")
input = read.csv("dulieu2.csv", header = T)
input = na.omit(input)

#data1 = input
#i = 1
#need_delete1 = vector()

# for (i in 1:nrow(data1)) {
#   if(data1[i, 1]!="Government") {
#     need_delete1= c(need_delete1, i)
#   }
# }
# data1 = data1[-c(need_delete1), ]

#=> đây là code rác để tạo data1 chứa goverment
#b.
data1 = input[input$Segment=="Government", ]
data2 = input[input$Segment=="Midmarket", ]

#c. Lập bảng tần số cho product
productTable = table(input$Product)
print(productTable)

#d. Tính tổng doanh thu (Gross.sales) của từng loại mặt hàng (Product). 
aggregate()
