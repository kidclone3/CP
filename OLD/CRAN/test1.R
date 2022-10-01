# a
height = c(150, 155, 160, 160, 164, 170, 161, 159, 152, 165)
sum(height>155) # hàm đếm
# b
# fix(height) # c1: dùng được với ít dữ liệu
height = replace(height, height == 152, 150)
height
