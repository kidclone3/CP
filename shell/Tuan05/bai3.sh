gt=0
ans=1
sum=0
giaithua(){
    for((i= 1; i<= $1; i++))
    do 
        ans=$(($ans*$i))
        sum=$(($sum + $ans))
    done
    gt=$ans
}
# a)
n=$1
giaithua $n
s1=$gt
echo "$s1"

# b)

echo "$sum"