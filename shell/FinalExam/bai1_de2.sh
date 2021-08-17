declare -a arr 
read -a arr 

max() {
    ans=""
    mx=${arr[0]}
    for it in ${arr[@]}
    do
        if ((it > mx))
        then
            mx=$it
            ans=$it
        elif ((it == mx))
        then
            ans="$ans $it"
        fi
    done 
    echo $ans
}
isPrime() {
    if (($1 < 2)) 
    then
        return 0
    fi
    for ((i=2; i*i <= $1; ++i)) 
    do
        if (($1 % i == 0)) 
        then
            return 0
        fi
    done
    return 1
    # $? = 0 => False
    # $? = 1 => True
}
listPrime() {
    ans=""
    for it in ${arr[@]}
    do
        isPrime $it
        if (($? == 1)) 
        then
            ans="$ans $it"
        fi
    done
    echo $ans
}

sum_odd() {
    sum=0
    for it in ${arr[@]}
    do
        if ((it % 2 == 1))
        then
            sum=$((sum+it))
        fi
    done
    echo $sum
}
day_don_mot() {
    # $? = 1 => True
    # $? = 2 => False
    n=${#arr[@]}
    if ((n==1)) 
    then
        return 1
    fi
    # Dung 2 con tro.
    i=1
    j=$((n - 2))
    while (( i < n && arr[i] > arr[i-1])) 
    do
        i=$((i+1))
    done
    while (( j >= 0 && arr[j] > arr[j+1]))
    do
        j=$((j-1))
    done
    if (( i == n)) 
    then
        return 1
    fi
    echo "$((j+1))"
    if (( j + 1 == i - 1)) 
    then
        return 1
    else
        return 0
    fi
}
dialog --backtitle "Bài thi cuối kì" --title "Bài 1" --menu "Bam lên, xuống và enter" 30 40 5 Option0 "Thoát" Option1 "Số lớn nhất" Option2 "Tổng các số lẻ" Option3 "Các số nguyên tố trong mảng" Option4 "Kiểm tra dãy đơn mốt" 2>tmp.$$
opt=`cat tmp.$$`
case $opt 
in
    Option0) 
        exit
        ;;
    Option1)
        ans2=`max`
        dialog --backtitle "Lựa chọn 1" --title "Tìm và in ra các số lớn nhất trong mảng vừa nhập." --infobox "$ans2" 30 50
        sleep 1
        ;;
    Option2) 
        ans2=`sum_odd`
        dialog --backtitle "Lựa chọn 2" --title "Tìm và in ra tổng các số lẻ trong mảng." --infobox "$ans2" 30 50
        sleep 1
        ;;
    Option3)
        ans2=`listPrime`
        dialog --backtitle "Lựa chọn 3" --title "Tìm và in ra số nguyên tố trong mảng" --infobox "$ans2" 30 50
        sleep 1
        ;;
    Option4) 
        day_don_mot
        if (($? == 1)) 
        then
            ans2="Đây là dãy đơn mốt"
        else
            ans2="Đây không là dãy đơn mốt"
        fi
        dialog --backtitle "Lựa chọn 4" --title "Đây có là dãy đơn mốt hay không?" --infobox "$ans2" 30 50
        sleep 1
        ;;
        
esac
rm tmp.$$