ID = c(1:300)
age = sample(18:24, 300, replace = T)
#View(age)
height = sample(130:190, 300, replace = T)
#height
thuongxuyen = sample(0:10, 300, replace = T)
giuaky = sample(0:10, 300, replace = T)
cuoiky = sample(0:10, 300, replace = T)

bangdiem = data.frame(ID, age, height, thuongxuyen, giuaky, cuoiky)
View(bangdiem)

sinhvientot = bangdiem[bangdiem$cuoiky >= 9, ]
View(sinhvientot)

# sinh vien co id = 5 co chuyen can bi sai, sua thanh 10
bangdiem[5, 4] <- 10
# bangdiem = replace(bangdiem$thuongxuyen, bangdiem$ID == 5, 10)

tongdiem = bangdiem$thuongxuyen * 0.2 + bangdiem$giuaky * 0.2 + bangdiem$cuoiky * 0.6
bangdiem = data.frame(bangdiem, tongdiem)

diemchu = tongdiem
diemchu[diemchu >= 9.0] = "A+"
diemchu[diemchu >= 8.5 & diemchu <9] = "A"
diemchu[diemchu >= 8.0 & diemchu <8.5] = "B+"
diemchu[diemchu >= 7.0 & diemchu <8.0] = "B"
diemchu[diemchu < 7.0] = "C"

bangdiem = data.frame(bangdiem, diemchu)
id10 = bangdiem[10,]
print(id10$diemchu)

cuoikytren9 = bangdiem[bangdiem$cuoiky >= 9.0,]
print(cuoikytren9$diemchu)

# bai 2.
setwd("/home/delus/Documents/code/CRAN/OnThi/")
data = read.csv("WHO1.csv", header = T)
na.omit(data)
Japan = data[data$Country == "Japan",]
Denmark = data[data$Country == "Denmark",]

Japan$LifeExpectancy..Tuoitho. >= Denmark$LifeExpectancy..Tuoitho.

Canada = data[data$Country == "Canada",]
Canada$FertilityRate..Tylesinhsan.

Country_max = data[data$Population..Danso. == max(data$Population..Danso),]
Country_max$Country
