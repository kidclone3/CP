#!/bin/bash
# Menu
check_folder() {
    echo "Thu muc hien tai la: "
    echo `pwd`
    echo "Ngay gio hien tai: "
    echo `date`
}
count_file_and_folder() {
    echo "So luong file va thu muc hien tai la: `ls | wc -w`"
}
count_process_running() {
    echo "So luong tien trinh dang chay la: $((`ps aux | wc -l` - 2))"
}
print_line_with_th() {
    echo "Cac dong co chu th trong /etc: "
    ls /etc | grep "th"
}
find_all_things_with_letter_b() {
    echo "Dang tim kiem...3..2..1"
    sleep 3
    ls /etc | grep -E "^.*b+.*$" > file_list.txt
    echo "Da tim xong. Ket qua luu vao file \"file_list.txt\""
}
find_numbers_divisible_to_5 () {
    echo "Dang tim kiem...3..2..1"
    for i in `cat dataset.txt` 
    do
        if (($i % 5 == 0)) 
        then
            echo -n "$i " >> number_list.txt
        fi
    done
    echo "Xong. Ket qua duoc luu vao file \"number_list.txt\""
}
find_phone_number() {
    echo "Dang tim kiem...3..2..1"
    cat dataset.txt | grep "^028.*" >> phone_list.txt
    echo "Xong. Ket qua duoc luu vao file \"phone_list.txt\""

}
kdialog --backtitle "Bai tap 1" --title "Menu" 1 "Check folder" 2 "Counting files and folder" 3 "Counting processes running" 4 "Printing lines with \"th\"" 5 "Find all things with letter \"b\"" 6 "Find all numbers divisible to 5" 7 "Find HCM phone numbers" 0 "exit" 2>/tmp/menuitem.$$
inp=`cat /tmp/menuitem.$$`
# while(true)
# do
    echo "-------------Menu-------------"
    echo "Moi ban chon cac to tu 1-7"
    echo "Bam so 0 de thoat"
    echo "------------------------------"
    # declare -i inp=0
    case $inp in
        1)
            check_folder
            ;;
        2)
            count_file_and_folder
            ;;
        3) 
            count_process_running
            ;;
        4)
            print_line_with_th
            ;;
        5)
            find_all_things_with_letter_b
            ;;
        6)
            find_numbers_divisible_to_5
            ;;
        7)
            find_phone_number
            ;;
        0)
            exit
            ;;
        *) 
            echo "Nhap lai"
            ;;
    esac
# done
