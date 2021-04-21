cal() {
    n1=$1
    op=$2
    n2=$3
    if (($# == 3)) 
    then
        ans=$(($n1 $op $n2))
        echo $ans
    else
        echo "LOI CMNR"
    fi
}
cal 1 + 2
cal 2 + 3
cal 5 / 5
cal 3 '*' 5
