bill = c(46,33,39,37,46,30,48,32,49,35,30,48)

# a) Tong so tien trong 12 thang
bill_sum = sum(bill)
cat(c("Tong so tien trong 12 thang la:",bill_sum))

# b) 
pay_more_40 = sum(bill>40)
cat(c("So thang phai tra hon 40$: ",pay_more_40), sep="")
cat(c("Ti le phan tram: ", pay_more_40/12*100, "%"), sep="")
