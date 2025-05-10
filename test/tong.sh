#! /bin/bash/

tong = 0
echo "Nhap so tu nhien N "

read n
for ((i = 1; i<=$n; i++))
do
    echo -n "Cac so tu 1 den N la : " $i
    tong = $(($tong + $i))
done
    echo "Tong cac so tu 1 den N la : " $tong
exit()

