ans=0
chan=0
le=0
for ((i=1; i<=$1; i++))
do
    ans=$(($ans+$i))
    if (($i % 2 == 0)) 
    then
        chan=$(($chan + $i))
    else   
        le=$(($le + $i))
    fi
done
echo "$ans $chan $le"