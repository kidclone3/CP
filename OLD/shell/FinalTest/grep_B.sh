while((1==1))
do
    read input
    if (($? != 0))
    then
        break
    fi
    for ((i=0; i < 10; ++i))
    do
        echo $input | grep -E "$i ?$i"
        # echo $?
        # echo $ans
        # ans=`echo $input | grep "$i ?$i"`
        if (($? == 0))
        then   
            # echo $ans
            break
        fi
    done
    # echo "$?"
done
