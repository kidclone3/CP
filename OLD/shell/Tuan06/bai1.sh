# array=(1 2 3 4)
read -a arr
echo ${arr[3]}
# echo ${#arr[*]}
for i in "${arr[@]}"
do
    echo $i
done