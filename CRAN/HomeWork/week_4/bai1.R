# 1.a
id = 1:300
gt = sample(c("Nam", "Nu"), 300, replace = T)
tuoi = sample(18:24, 300, replace = T)
chieucao = rnorm(300, 165, 5)
cannang = rnorm(300, 60, 5)
thuongxuyen = sample(1:10, 300, replace = T)
giuaky = sample(seq(0, 10, 0.5), 300, replace = T)
cuoiky = sample(seq(0, 10, 0.5), 300, replace = T)
sv = data.frame(id, gt, tuoi, chieucao, cannang, thuongxuyen, giuaky, cuoiky)

#1.b
svtot = subset(sv, cuoiky>=9) 
tmp = data.frame(id, gt, tuoi, chieucao, cannang, thuongxuyen, giuaky, cuoiky)
sv = tmp
#1.c
sv[5,6] = 10

#1.d
tongdiem = thuongxuyen * 0.2 + giuaky*0.2 + cuoiky*0.6
sv = data.frame(sv, tongdiem)

#1.e
diemchu = tongdiem
diemchu = replace(diemchu, diemchu>=9.0, "A+")
diemchu = replace(diemchu, diemchu>=8.5 & diemchu <9, "A")  
diemchu = replace(diemchu, diemchu>=8.0 & diemchu <8.5, "B+") 
diemchu = replace(diemchu, diemchu>=7.0 & diemchu <8.0, "B")
diemchu = replace(diemchu, diemchu<7.0, "C")
sv = data.frame(sv, diemchu)

#cout<<diemchu[10]
print(diemchu[10])

#1.f cout<<diem chu cua sinh vien co diem cuoi ky >=9
print(svtot$diemchu)

#1.ff cout<< diem chu cua thanh nien id = 125
id_125 = subset(sv, sv$id == 125)
print(id_125$diemchu)
