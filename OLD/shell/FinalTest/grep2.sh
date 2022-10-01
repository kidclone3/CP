while((1==1))
do
    read input
    if (($? != 0))
    then
        break
    fi
    echo $input | grep -E -i " the "
done