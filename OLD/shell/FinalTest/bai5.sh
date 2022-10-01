# tinh tong tu 1 den 10 dung de quy
# sum s_1 s_2
# s_1 la i (1->10)
# s_2 la tong (1->i)
sum(){
    if (($1>10))
    then
        echo $2
        return
    fi
    sum $(($1+1)) $(($2+$1))
}
tmp=`sum 1 0`
echo $tmp
# echo "$?"
# echo ""