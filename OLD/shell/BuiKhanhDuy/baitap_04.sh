#!/bin/zsh
echo "bieu dien tap cac so tu nhien"
cat file.txt | grep -E "^[1-9][0-9]*$"
echo "------------\n"

echo "bieu dien tap cac so thuc"
cat file.txt | grep -E "^-?[1-9][0-9]*[.]?[0-9]*$"
echo "------------\n"

echo "bieu dien tap so tu nhien chia het cho 5"
cat file.txt | grep -E "^[1-9][0-9]*[05]+$"
echo "------------\n"
# bieu dien tap so tu nhien chia het cho 5 va co do dai chan
# chiu :))

echo "Tap cac dong bat dau = chu cai T va co 2 cau \"this is an exercise\""
cat file.txt | grep -E "^T.*(this is an exercise).*(this is an exercise).*$"
echo "------------\n"
# cau lenh ls vs grep
echo "Co chua it nhat 2 chu cai 'a'"
ls /etc | grep -E "^.*a.*a.*$" > output1.txt
echo "------------\n"

echo "Chu cai dau la b va ko chua chu cai c"
ls /etc | grep -E "^b[^c]*$" > output2.txt
echo "------------\n"


