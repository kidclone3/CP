#!/bin/bash
date=`date +%H`
# date=13
echo "$date"
if (( 0 < $date && $date < 12 )) 
then 
    echo "Chao buoi sang"
elif (( 12 <= $date && $date < 18))
then 
    echo "Chao buoi chieu"
else 
    echo "Chao buoi toi"
fi