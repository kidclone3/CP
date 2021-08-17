declare -a arr 
read -a arr 

# sum=0
#     for it in ${arr[@]}
#     do
#         if ((it % 2 == 1))
#         then
#             sum=$((sum+it))
#         fi
#     done
#     echo $sum
ans=""
    mx=${arr[0]}
    for it in ${arr[@]}
    do
        if ((it > mx))
        then
            mx=$it
            ans=$it
        elif ((it == mx))
        then
            ans="$ans $it"
        fi
    done 
    echo $ans