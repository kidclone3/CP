function cal()
{
n1=$1
op=$2
n2=$3
ans=0
if [ $# -eq 3 ]
then
ans=$(( n1 $op n2 ))
echo "$n1 $op $n2 =$ans"
else
echo "Function cal requires at least three args"
fi
}
cal 5 + 10
cal 10 - 2
cal 10 * 2
