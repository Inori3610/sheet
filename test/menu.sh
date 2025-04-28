#!/bin/bash/
#

while :; do
    echo "Server name : "
    echo "-----------------------------"
    echo "  MAIN - MENU"
    echo "-----------------------------"
    echo "1. Display date time now"
    echo "2. Display current online account"
    echo "3. Display connected Internet"
    echo "4. Check this machine IP"
    echo "5. IP has Internet ? "
    echo "6. Exit"
    echo "Enter your choice : "
    read choice

    case $choice in
    1)
        date +"Today is %d th on month %m in year %Y"
        read -p "Enter [Enter] to continue....."
        readEnterKey
        ;;

    2)
        w
        read -p "Enter [Enter] to continue..."
        readEnterKey
        ;;

    3)
        netstat -nat
        read -p "Enter [Enter] to continue..."
        readEnterKey
        ;;

    4)
        ifconfig -a
        read -p "Enter [Enter] to continue..."
        readEnterKey
        ;;

    5)
        if ping -q -c 1 -W 1 8.8.8.8 >/dev/null; then
            echo "IPv4 is online"
        else
            echo "IPv4 is offline"

        fi
        read -p "Enter [Enter] to continue..."
        readEnterKey
        ;;

    6)
        echo "Goodbye"
        exit 0
        ;;

    *)
        echo "Error : Invalid choice"
        read -p "Enter [Enter] to continue"
        ;;
    esac

done
