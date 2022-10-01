while((1==1))
do
    read input
    if (($? != 0))
    then
        break
    fi
    echo $input | grep -E -i -e " ?the " -e " ?that " -e " ?then " -e " ?those "
    # echo "$?"
done
