a, b, c, d, e, f = map(int, input().split())
mx = -1
wat = 0
sug = 0
for a_i in range(0, 40):
    for b_i in range(0, 40):
        for c_i in range(0, 40):
            for d_i in range(0, 40):
                water = a_i*a + b_i*b
                sugar = c_i*c + d_i*d
                if (100*(water) + sugar <= f) and (sugar <= e*(water)):
                    if (water != 0 and sugar/(100*water+sugar) > mx):
                        mx = sugar/(100*water+sugar)
                        wat = 100*water
                        sug = sugar
print(wat + sug, sug, sep = " ")
            
      