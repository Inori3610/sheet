#!/bin/bash/

tong=0
n=100

for ((i = 0; i <= $n; i++)); do
    if [ $(($i % 2)) -eq 0 ]; then
        if [ $(($i % 5)) -eq 0 ]; then
            tong=$(($tong + $i))
        fi
    fi
done

echo $tong

exit 0
