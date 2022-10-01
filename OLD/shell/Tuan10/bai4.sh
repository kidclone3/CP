dialog --title "Menu" --backtitle "Backtitle" --menu "Bam len xuong de chon" 10 50 3 Date "Hien thi ngay" List "Liet ke cac file va thu muc" Process "Liet ke tien trinh" 2>input.txt
if [ $? -eq 0 ]
then
    inp=`cat input.txt`
    case $inp in 
        Date) 
            echo `date`
            # break
            ;;
        List)
            echo `ls`
            # break
            ;;
        Process)
            echo `ps    `
            # break
            ;;
        *)
            echo "Nothing"
            # break
            ;;
    esac
else
    echo "Ban da thoat"
fi
rm input.txt