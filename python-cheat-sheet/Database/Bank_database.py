import os
import sqlite3

database_name = "bank.db"


def connect_db():
    return sqlite3.connect(database_name)


def create_database():
    if not os.path.exists(database_name):
        with connect_db() as conn:
            print(f"Make new Database {database_name}")
            create_table()
    else:
        print(f"Database {database_name} is already exists, Only make if do not have")
        create_table()


def create_table():
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute("""CREATE TABLE IF NOT EXISTS accounts (
                            ID TEXT PRIMARY KEY,
                            OWNER TEXT,
                            BALANCE FLOAT)""")
        conn.commit()


create_database()


def display():
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM accounts")
        ACC = cursor.fetchall()
        if ACC:
            print("List accounts : ")
            for acc in ACC:
                print(f"- {acc[0]} | OWNER : {acc[1]} | BALANCE : {acc[2]}")
        else:
            print("There aren't any accounts")


def add_acc(ID, OWNER, BALANCE):
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO accounts (ID,OWNER,BALANCE) VALUES (?,?,?)",
            (ID, OWNER, BALANCE),
        )
        conn.commit()


def tang5():
    with connect_db() as conn:
        cursor = conn.cursor()

        cursor.execute("SELECT * FROM accounts")

        Acc = cursor.fetchall()
        if Acc:
            for ac in Acc:
                if ac[2] > 100000000:
                    fi = ac[2] + ac[2] * 0.05
                    cursor.execute(
                        "UPDATE accounts SET BALANCE = ? WHERE ID = ? ", (fi, ac[0])
                    )
                    conn.commit()


def menu():
    print(
        "----------------------------------MENU-----------------------------------------"
    )
    print("1. Add new account")
    print("2. Display all accounts")
    print("3. Plus 5% if acc balance > 100000000")


def main():
    loop = True
    choice = 0
    while loop:
        menu()
        choice = int(input("Enter your choice : "))
        match choice:
            case 1:
                id = input("Enter id : ")
                owner = input("Enter owner name : ")
                balance = float(input("Enter balane : "))
                add_acc(id, owner, balance)
                print(f"Added owner {owner} successfully")
            case 2:
                display()
            case 3:
                tang5()
                display()


main()
