# awk 'BEGIN {count = 0; print "ok"} 
# {
#     # i1 = index($2, "_")
#     # dem_va_ten = substr($2, i1+1, length($2))
#     # i2 = index(dem_va_ten, "_")
#     # ten = substr(dem_va_ten, i2+1, length($2))
#     # print ten

#     i = length($2) - 1
#     for (; i >= 0; --i) {
#         if (substr($2, i, 1) == "_") {
#             break
#         }
#     }
#     print substr($2,i+1, length($2))

#     if ($3 <= 9) count++
# }
# END {print "end"}' demo.txt
mx=$(awk 'BEGIN {mx = 0; print ""}
    {
        dtb = ($3 + $4 + $5) / 3
        if (dtb > mx) {
            mx = dtb
        }
    }
END {print mx}' demo.txt)
echo $mx
awk 'BEGIN {max = $mx; print ""}
    {
        dtb = ($3 + $4 + $5) / 3
        if (dtb == max) {
            print $2
        }
    }
END {print mx}' demo.txt