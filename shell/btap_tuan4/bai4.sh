#!/bin/bash
choice=0
while (($choice != 5))
do
    echo "Xin moi ban chon hanh dong?"
    echo "1. Xem dung luong su dung cua may tinh."
    echo "2. Xem noi dung thu muc hien hanh."
    echo "3. Xem cac tien trinh dang chay tren may tinh duoi dang cay."
    echo "4. Xem ten nguoi dung dang nhap he thong."
    echo "5. Thoát"
    read choice
    case $choice
    in 
        1)
            free
            ;;
        2)
            ls
            ;;
        3)
            pstree
            ;;
        4)
            echo $USER
            ;;
        5)
            exit
            ;;
        *)
            echo "Moi ban nhap lai"
            ;;
    esac
done