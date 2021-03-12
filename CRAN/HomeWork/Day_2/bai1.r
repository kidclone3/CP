# a) Nhap du lieu
pr = c(9000,9500,9400,9400,10000,9500,10300,10200)
estimate = 9500

# b) So sanh
medium = mean(pr)
print("Gia tri trung binh la :", end="")
print(medium)
if (medium > estimate) {
  print("Lon hon uoc luong cua Edmund")
} else if (medium == estimate) {
  print("Bang uoc luong cua Edmund")
} else {
  print("Be hon uoc luong cua Edmund")
}

# c) So luong cua hang ban dat hon Edmund du doan.
counter = sum(pr>estimate)
print(counter)
