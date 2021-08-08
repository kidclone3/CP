# Bai 1:
# Cau 1:
echo "Cac so tu nhien"
cat dataset.txt | grep -E "^[1-9][0-9]+$"
echo "-------------------"
# Cau 2:
echo "Cac so tu nhien chia het cho 5"
cat dataset.txt | grep -E "^[1-9][0-9]*[05]$"
echo "-------------------"
# Cau 3:
echo "Tap cac so nhi phan co do dai 6 va chia het cho 4"
cat dataset.txt | grep -E "^[01]{6}$" | grep -E "00$"
echo "-------------------"
# Cau 4:
cat dataset.txt | grep -E "^T" | grep -E ".*This is an exercise.*This is an exercise.*"

# grep "Bai 2:"
echo "Bai 2"
echo "-------------------"
ls /etc | grep -E "^.*a.*a.*$" > output1.txt
echo "-------------------"
ls /etc | grep -E "^b[^c]*$" > output1.txt
echo "-------------------"
cat "name_list.txt" | grep -E -i "^jiayant" > output1.txt
echo "-------------------"
cat "phone_list.txt" | grep -E -i "^024-[0-9]{7}$" > output1.txt