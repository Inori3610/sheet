#!/bin/bash/

echo "Nhap vao so thu muc can tao : "
read n

for ((i = 1; i <= n; i++)); do
    mkdir "Thumuc$i"
done

echo "Da tao $n thu muc"
