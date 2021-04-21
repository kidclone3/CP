#!/bin/bash
echo "Tuan 07: Cac toan tu trong lap trinh shell va Vong lap" > tailieu.txt
for (( i = 1; i <= 3; i++ ))
do
    # echo "$i"
    tmp="tailieu_$i.txt"
    cp tailieu.txt $tmp
    # echo $tmp
done 