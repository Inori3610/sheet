#!/bin/bash

tong=0
n=100

for ((i = 1; i <= n; i++)); do
    if [ $((i % 5)) -eq 0 ] && [ $((i % 2)) -eq 0 ]; then
        tong=$((tong + i))
    fi
done
echo $tong
