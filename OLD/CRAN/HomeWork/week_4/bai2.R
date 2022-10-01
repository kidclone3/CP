# a
setwd("/home/delus/Documents/code/CRAN/HomeWork/week_4")
input = read.csv("WHO1.csv", header = T)
input = na.omit(input) # loai bo cac du lieu trong.

# b
# trich ra du lieu cua Bahrain
Bahrain = subset(input, input$Country == "Bahrain")

# trich ra du lieu cua Mexico
Mexico = subset(input, input$Country == "Mexico")
Mexico = input[input$Country == "Mexico", ]
# so sanh tuoi tho? (Bahrain c?? 1 ?? b??? NA n??n ph???i b???  d??ng 3 th?? m???i ch???y ???????c)
#print(Bahrain$LifeExpectancy..Tuoitho.)
#print(Mexico$LifeExpectancy..Tuoitho.)

if (Bahrain$LifeExpectancy..Tuoitho. > Mexico$LifeExpectancy..Tuoitho.) {
  print("Bahrain co tuoi tho cao hon", end="\n")
}else if (Bahrain$LifeExpectancy..Tuoitho. < Mexico$LifeExpectancy..Tuoitho.) {
  print("Mexico co tuoi tho cao hon", end="\n")
}else {
  print("Hai nuoc co tuoi tho ngang nhau")
}

#c. Cho bi???t t??? l??? sinh s???n c???a n?????c Canada
Canada = subset(input, input$Country == "Canada")
print(Canada$FertilityRate..Tylesinhsan.)

#d. Phan nhom cac quoc gia.
category = input$GNI..Thunhapquocdan.
category[category > 20000] = "Phat trien"
category[category >= 10000 & category <= 20000] = "Dang phat trien"
category[category < 10000] = "Chua phat trien"

print(category)
input = data.frame(input, category)
# Trung quoc thuoc nhom nao?
China = subset(input, input$Country=="China")
print(China$category)

kiemtra = function(x = c(""), y) {
  nhom = y[,10]
  
}
# e. Tim nuoc co dan so cao nhat.
#print(nrow(input))
max_polulation = 0
max_country = "a"
for (i in 1:nrow(input)) {
  if (input[i,3] > max_polulation) {
    max_country = input[i,1]
    max_polulation = input[i,3]
  }    
}
print(max_country)  
