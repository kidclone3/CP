read n
read -a arr
isPerfect(){
    if (($1 == 1))
    then
        return 0
    fi
    ans=1
    for ((i=2; i*i <= $1; ++i))
    do 
        if (($1 % i == 0))
        then
            if ((i != $1/i))
            then
                ans=$((ans + i + $1/i))
            else
                ans=$((ans + i))
            fi
        fi
    done
    return $((ans==$1))
}
# perfect_number(){
    declare i=0
    # declare ans1=""
    declare -a ans1=()
    dem=0
    for it in ${arr[@]}
    do
        isPerfect $it
        if (($? == 1)) 
        then
            ans1+="$it "
            # ans="$ans $it"
            # echo "$it"
            # tmp=$it
            # ans[dem]=$tmp
            # echo "${ans[dem]} $dem"
            # dem=$((dem+1))
        fi
    done
    echo ${ans1[@]}
    # for it in ${ans[@]}
    # do
    #     echo -n "$it "
    # done