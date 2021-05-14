#!/bin/bash
declare -a array
read -a array
check() {
    for ((i=0;i<${#array[@]} - 1;i++))
    do
        if [ $((array[i]*array[i+1])) -gt 0 ] 
        then
            return 0
        fi
    done
    return 1
}
check
if [ $? -eq 1 ]
then
    echo "Day la day dan dau"
else
     echo "Day khong la day dan dau"
fi