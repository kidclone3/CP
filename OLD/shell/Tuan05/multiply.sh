multiply() {
    if [$2 -ge 10] 
    then
        return 0
    else
        ans=$(($1 * $2))
        echo "$1 * $2 = $ans"
        if(($2+1 <= 10))
        then
            multiply $1 $(($2+1))
        fi
    fi
}
multiply $1 1
# for ((i = 1; i <= 10; i++))
# do
#     ans=$(($1 * $i))
#     # ans=$1 * $i
#     echo "$1 * $i = $ans"  
# done
