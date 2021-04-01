# a
setwd("/home/delus/Documents/code/CRAN/HomeWork/day_4")
input = read.csv("WHO1.csv", header = T)
input = na.omit(input) # loai bo cac du lieu trong.

# b
# trich ra du lieu cua Bahrain
Bahrain = subset(input, input$Country == "Bahrain")
# trich ra du lieu cua Mexico
Mexico = subset(input, input$Country == "Mexico")

# so sanh tuoi tho? (Bahrain có 1 ô bị NA nên phải bỏ  dùng 3 thì mới chạy được)
print(Bahrain$LifeExpectancy..Tuoitho.)
print(Mexico$LifeExpectancy..Tuoitho.)

if (Bahrain$LifeExpectancy..Tuoitho. > Mexico$LifeExpectancy..Tuoitho.) {
  print("Bahrain co tuoi tho cao hon", end="\n")
}else if (Bahrain$LifeExpectancy..Tuoitho. < Mexico$LifeExpectancy..Tuoitho.) {
  print("Mexico co tuoi tho cao hon", end="\n")
}else {
  print("Hai nuoc co tuoi tho ngang nhau")
}

#c. Cho biết tỉ lệ sinh sản của nước Canada
Canada = subset(input, input$Country == "Canada")
print(Canada$FertilityRate..Tylesinhsan.)

#d. Phan nhom cac quoc gia.
category = input[,10]
phan_nhom = vector()
for (i in category) {
  if (i>=10000 & i <= 20000) {
    phan_nhom = c(phan_nhom, "Dang phat trien")
  }else if (i<5000) {
    phan_nhom = c(phan_nhom, "Chua phat trien")
  }else {
    phan_nhom = c(phan_nhom, "Quoc gia khac")
  }
}
input = data.frame(input, phan_nhom)

# Trung quoc thuoc nhom nao?
China = subset(input, input$Country=="China")
print(China$phan_nhom)

# e. Tim nuoc co dan so cao nhat.
print(nrow(input))
max_polulation = 0
max_country = "a"
for (i in 1:nrow(input)) {
  if (input[i,3] > max_polulation) {
    max_country = input[i,1]
    max_polulation = input[i,3]
  }    
}
print(max_country)  
