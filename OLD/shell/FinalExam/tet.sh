declare -a arr
read -a arr 
 # $? = 1 => True
    # $? = 2 => False
    n=${#arr[@]}
    if ((n==1)) 
    then
        return 1
    fi
    # Dung 2 con tro.
    i=1
    j=$((n - 2))
    while (( i < n && arr[i] > arr[i-1])) 
    do
        i=$((i+1))
    done
    while (( j >= 0 && arr[j] > arr[j+1]))
    do
        j=$((j-1))
    done
    if (( i == n)) 
    then
        return 1
    fi
    echo "$((j+1))"
    if (( j + 1 == i - 1)) 
    then
        return 1
    else
        return 0
    fi