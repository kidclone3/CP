dialog --title "DBRR" --backtitle "AGRRHHHH" --infobox "ARE U SERIOUS???" 7 50 --yesno "EXIT" 15 20
case $? in 
    0) echo "YES"   ;;
    1) echo "NO"
       exit    ;; 
    255) echo "CANCEL"  ;;
esac
dialog --title "INPUT BOX" --inputbox "ENTER NAME " 8 60 2>/tmp/input.$$
sel=$?
na=`cat /tmp/input.$$`
case $sel in
    0) echo "HELLO $na" ;;
    1) echo "Again"     ;;
    255) echo "CANCEL"  ;;
esac

dialog --title "MENU" --menu "MOVE USING [Up] [Down] "