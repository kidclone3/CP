find_numbers_divisible_to_5 () {
    echo "Dang tim kiem...3..2..1"
    cat dataset.txt | grep -E "[05]$" > number_list.txt
    # echo $?
    if [[ $? -eq 0 ]]
    then
        echo "Xong. Ket qua duoc luu vao file \"number_list.txt\""
    fi
}
find_phone_number() {
    echo "Dang tim kiem...3..2..1"
    cat dataset.txt | grep -E "^028-[0-9]{7}$" > phone_list.txt
    echo "Xong. Ket qua duoc luu vao file \"phone_list.txt\""

}
find_numbers_divisible_to_5
find_phone_number