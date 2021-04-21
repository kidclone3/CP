#!/bin/bash
for ((i = 1; i < 5; i++))
do
    file="file_$i.txt"
    echo "Toi la sinh vien $i" > $file
done