file=$1
mx="a"
length=0
for line in `cat $file`
do
    now=`echo $line | wc -m`
    # now=${#line}
    if ((now > length)) 
    then   
        length=$now
        mx=$line
    fi
done
echo "$mx"