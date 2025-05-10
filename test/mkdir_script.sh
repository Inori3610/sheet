#!/bin/bash

echo "Enter number of folder to make"
read n

for ((i = 1; i <= n; i++)); do
    mkdir "Folder$i"
done

echo "Done making $n folder"
