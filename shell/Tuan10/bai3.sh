dialog --title "Title" --backtitle "Backtitle" --inputbox "Moi nhap ten" 7 50 2>input.txt
if [ $? -eq 0 ]
then
    echo "Ten cua ban la: `cat input.txt`"
else 
    echo "Ban da thoat"
fi
rm input.txt