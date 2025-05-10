#! /bin/bash
echo "Thuc hien copy trong linux"

read -p "nhap ten file can copy : " file1

read -p "nhap ten folder chua file : " file2

cp $file1 $file2 >/dev/null
if [$? -eq 0]; then
    echo "Copy successfuly"
else
    echo "Copy fail"
fi
