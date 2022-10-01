awk 'BEGIN {max=0;name=""}
{
	dtb=($3+$4+$5)/3
	if(dtb>max){
		max=dtb
		name=$2
	}
	else if(dtb==max){
		name=name"\t"$2
	}
}
END {print ""}' demo.txt