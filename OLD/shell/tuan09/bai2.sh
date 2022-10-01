__gcd() {
    if [[ $2 -eq 0 ]]
    then
        echo $1
    else
        echo `__gcd $2 $(($1 % $2))`
    fi
}
__lcm() {
    gcd=`__gcd $1 $2`
    echo $(( $1 * $2 / gcd))
}
echo `__gcd 4 6`
echo `__lcm 4 6`
echo `__gcd 7 11`
echo `__lcm 7 11`