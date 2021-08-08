# read file_name
# if [[ -e $file_name ]]
# then
#     cat $file_name
# else
#     echo "file ko ton tai"
# fi
# hour=`date +%H`
# if (( hour <= 12 ))
# then
#     echo "Ohayo!"
# elif ((hour < 19))
# then
#     echo "Konichiwa!"
# else
#     echo "Konbawa!"
# fi
# input=0
# while((input != 5)) 
# do
#     echo "-------------------------"
#     echo "Xin moi ban chon hanh dong?"
#     echo "1. Xem dung luong su dung cua may tinh."
#     echo "2. Xem noi dung thu muc hien hanh."
#     echo "3. Xem cac tien trinh dang chay tren may tinh duoi dang cay."
#     echo "4. Xem ten nguoi dung dang nhap he thong."
#     echo "5. Thoát"
#     read input
#     case $input
#     in 
#         1)
#             free
#             ;;
#         2)
#             ls -la
#             ;;
#         3)
#             ps -aux
#             ;;
#         4)
#             whoami
#             ;;
#         *)
#             ;;
#     esac
# done
bai 6
for ((i=1; i<=3; ++i))
do
    file_name="tailieu_$i.txt"
    # cat tailieu.txt > $file_name =>good
    cp tailieu.txt $file_name
    # echo "" > $file_name
    # for copy in `cat tailieu.txt`
    # do
    #     echo $copy >> $file_name
    # done
done
# bai7
for ((i=1; i<=4; ++i))
do
    file_name="file_$i.txt"
    echo "Toi la sinh vien $i" > $file_name
done

