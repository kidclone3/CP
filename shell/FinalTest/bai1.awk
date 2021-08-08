BEGIN {print "---------------"}
{
    # sum = $3 + $4 + $5
    # sum = sum/3
    # print $2 " = " sum
    i = index($2, "_")
    ans = substr($2, 0, i-1)
    print ans
}
END {print "---------------"}