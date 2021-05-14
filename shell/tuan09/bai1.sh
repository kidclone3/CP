# Mang dan dau.
dandau() {
    a=("$@")
    # for ((i = 0; i < ${#a[@]}; ++i))
    # do
    #     echo "${a[$i]}"
    # done
    for (( i = 1; i < ${#a[@]}; ++i ))
    do
        if (($((a[i] * a[i-1])) >= 0)) 
        then
            return 1
        fi
    done
}
declare -a arr
read -a arr

dandau "${arr[@]}"
if [[ $? -eq 0 ]] 
then
    echo "La mang dan dau"
else 
    echo "Khong la mang dan dau"
fi
