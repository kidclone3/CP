declare -a a
read -a a
check() {
    n=${#a[@]}
    if [ $n -eq 1 ]
    then
        return 0
    fi
    i=1
    j=$((n - 2))
    while (( i < n && $((a[i] - a[i-1])) > 0 )) 
    do
        i=$((i+1))
    done
    while (( j >= 0 && $((a[j] > a[j+1])) ))
    do
        j=$((j-1))
    done
    if (( i == n)) 
    then
        return 0
    fi
    if (( j + 1 == i - 1)) 
    then
        return 0
    else
        return 1
    fi
}
check
if [ $? -eq 0 ]
then   
    echo "La day don mot"
else 
    echo "Khong la day don mot"
fi