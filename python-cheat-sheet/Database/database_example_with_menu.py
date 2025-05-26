import os
import sqlite3

database_name = "hotel.db"


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
        cursor.execute("""CREATE TABLE IF NOT EXISTS rooms (
                            ID INTEGER PRIMARY KEY AUTOINCREMENT,
                            ROOM_NUMBER TEXT,
                            ROOM_TYPE TEXT,
                            PRICE REAL)""")
        conn.commit()


create_database()


def display_room():
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM rooms")
        ROOM = cursor.fetchall()
        if ROOM:
            print("List Room in hotel : ")
            for ro in ROOM:
                print(
                    f"- {ro[0]} | Room name : {ro[1]} | Type : {ro[2]} | Price : {ro[3]}"
                )
        else:
            print("There are't any room in the hotel")


def display_room_spe():
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM rooms")
        ROOM = cursor.fetchall()
        if ROOM:
            print("List all rooms price from range 500000 to 1000000 : ")
            for ro in ROOM:
                if 500000 <= ro[3] <= 1000000:
                    print(
                        f"- {ro[0]} | Room name : {ro[1]} | Type : {ro[2]} | Price : {ro[3]}"
                    )
        else:
            print("There aren't any rooms in hotel")


def add_room(ROOM_NUMBER, ROOM_TYPE, PRICE):
    print(
        "----------------------------------ADD ROOM-----------------------------------------"
    )
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO rooms (ROOM_NUMBER,ROOM_TYPE,PRICE) VALUES (?,?,?)",
            (ROOM_NUMBER, ROOM_TYPE, PRICE),
        )
        conn.commit()


def update_room(ID, new_room_number=None, new_room_type=None, new_price=None):
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute(
            "SELECT ROOM_NUMBER, ROOM_TYPE, PRICE FROM rooms WHERE ID = ?", (ID,)
        )
        current_values = cursor.fetchone()

        if not current_values:
            print(f"No room found with id = {ID}")
            return

        # this will keep old value if it blank else it will get new value good deal
        room_number = new_room_number if new_room_number else current_values[0]
        room_type = new_room_type if new_room_type else current_values[1]
        price = new_price if new_price else current_values[2]

        cursor.execute(
            "UPDATE rooms SET ROOM_NUMBER = ?, ROOM_TYPE = ?, PRICE = ? WHERE ID = ?",
            (room_number, room_type, price, ID),
        )
        conn.commit()
        print(f"Update room with id = {ID} successfully")


def delete_room(id):
    print(
        "----------------------------------DELETE ROOM-----------------------------------------"
    )
    with connect_db() as conn:
        cursor = conn.cursor()
        cursor.execute("DELETE FROM rooms WHERE ID = ?", (id,))
        conn.commit()
        print("DELETE rooms with id = {ID} successfully")


def menu():
    print(
        "----------------------------------MENU-----------------------------------------"
    )
    print("1. Add new room")
    print("2. Display all room")
    print("3. Update room")
    print("4. Delete room")
    print("5. Display room has price between 500000 and 1000000")
    print("6. Exit")


def main():
    loop = True
    choice = 0
    while loop:
        menu()
        choice = int(input("Enter your choice : "))
        match choice:
            case 1:
                room_number = input("Enter Room Number : ")
                room_type = input("Enter Room Type : ")
                price = float(input("Enter room price : "))
                add_room(room_number, room_type, price)
                print(f"Added room {room_number} successfully")
            case 2:
                display_room()
            case 3:
                print(
                    "--------------------------------------------UPDATE ROOM-------------------------------------------"
                )
                print("In case keep old data leave it blank ok >_o")
                id = int(input("Enter ID Room to Update"))
                room_number = input("Enter new room number : ")
                room_type = input("Enter new room type : ")
                price = input("Enter new room price : ")
                update_room(id, room_number, room_type, price)
            case 4:
                id = int(input("Enter ID Room to Delete : "))
                delete_room(2)
            case 5:
                display_room_spe()
            case 6:
                loop = False
    print("Exitting...")


main()
