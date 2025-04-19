#!/bin/bash/

echo "Enter a : "
read a
echo "Enter b : "
read b
echo "Enter c : "
read c

zero = 0
delta = $b*$b-4*$a*$c

echo "$delta"

if [ $delta -lt $zero ]; then
    echo "Phuong trinh vo nghiem"

elif [ $delta -gt $zero ]; then
    echo "Phuong trinh co 2 nghiem pham biet : x1 =  sqrt(-b)/2a"

elif [ $delta -eq $zero ]; then
    echo "Phuong trinh co nhiem kep x1=x2= -b/2a "
fi
