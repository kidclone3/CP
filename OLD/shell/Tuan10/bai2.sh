# sudo `clear`
dialog --title "Title" --backtitle "Backtitle" --yesno "Hay chon" 7 50
if [ $? -eq 0 ]
then
    echo "Da chon yes"
elif [ $? -eq 1 ]
then
    echo "Da chon no"
else 
    echo "Da bam nut esc"
fi