read n
declare -a arr 
read -a arr
max(){
    mx=${arr[0]}
    for it in ${arr[@]}
    do
        if ((mx < it))
        then
            mx=$it
        fi
    done
    echo $mx
}
min_even() {
    mn=1000000
    for it in ${arr[@]}
    do
        if ((it % 2 == 0 && mx > it))
        then
            mx=$it
        fi
    done
    if ((mn == 1000000)) 
    then
        echo "Not found"
    else
        echo mn
    fi
}
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
perfect_number(){
    declare ans1=""
    dem=0
    for it in ${arr[@]}
    do
        isPerfect $it
        if (($? == 1)) 
        then
            ans1+="$it "
            dem=$((dem+1))
        fi
    done
    echo "${ans1[@]}"
}

dialog --backtitle "Chuong trinh xin xo con bo" --title "Hello everybody" --menu "Bam len, xuong va Enter de chon" 15 30 4 Option1 "Tim so lon nhat" Option2 "Tim so chan nho nhat" Option3 "Tim so hoan hao" Option4 "Thoat" 2>tmp.$$
opt=`cat tmp.$$`
rm tmp.$$
case $opt
in
    Option1)
        ans2=`max`
        dialog --backtitle "Answer" --title "Option 1" --infobox "$ans2" 15 30; read
        ;;
    Option2)
        ans2=`min_even`
        dialog --backtitle "Answer" --title "Option 2" --infobox "$ans2" 15 30; read
        ;;
    Option3)
        ans2=`perfect_number`
        dialog --backtitle "Answer" --title "Option 3" --infobox "Day la dap an $ans2" 7 30 
        sleep 1
        ;;
    Option4)
        exit
        ;;
esac