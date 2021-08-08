find1()
{
    cat dataset.txt | grep -E "^0$" > number_list.txt
    cat dataset.txt | grep -E "[05]$" | grep -E "^[1-9][0-9]*$" >> number_list.txt
    echo 'Xong. Ket qua duoc luu vao file "number_list.txt"'
}
find1
