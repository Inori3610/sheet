file_name = "sochan.txt"
mang = [2, 4, 6, 7, 9]
with open(file_name, "wb") as f:
    for i in mang:
        if int(i) % 2 == 0:
            f.write(repr(i).encode())
with open(file_name, "rb") as f:
    for i in f.read():
        print(" mang doc tu file : " + chr(i) + " ")
