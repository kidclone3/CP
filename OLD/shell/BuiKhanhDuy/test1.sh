#!/bin/bash

echo "Buh buh lmao"
# read name
a=2
b=3
# sum='expr $a + $b'
echo $sum

case $1
in 
    1) echo "Nice, option 1";; # ;; <=> break.
    2) echo "Nah, option 2" ;;
    3) echo "Bruh, option 3?" ;;
    0) exit;;
    *) echo "Are you crazy???"
esac

echo "Method 2:\n"
for i in 1 2 3 4 5 6 7 8 9
do 
    echo $i
done

for (( i = 0 ; i < 10 ; i++ ))
do 
    echo -n "$i \t$(($i + 1))\n" 
done

if (( 1 <= 2 ))
then echo "YES"
fi