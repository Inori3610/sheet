import sqlite3

conn = sqlite3.connect(("QLBH.db"))

cursor = conn.cursor()

cursor.execute("""CREATE TABLE IF NOT EXISTS Sanpham(
                    Masp TEXT PRIMARY KEY,
                    Tensp TEXT,
                    Soluong INTEGER) """)

cursor.execute("""CREATE TABLE IF NOT EXISTS Hoadon(
                    Mahh INTEGER PRIMARY KEY,
                    Masp TEXT,
                    Soluong INTEGER,
                    FOREIGN KEY (Masp) REFERENCES Sanpham(Masp))""")

products = [
    ("SP1", "But", 50),
    ("SP2", "Vo", 100),
    ("SP3", "Tay", 30),
    ("SP4", "Thuoc", 20),
    ("SP5", "Keo", 40),
]

cursor.executemany("INSERT INTO Sanpham VALUES (?,?,?)", products)

invoices = [
    (1, "SP1", 10),
    (2, "SP2", 20),
    (3, "SP3", 5),
    (4, "SP1", 15),
    (5, "SP4", 2),
]

cursor.executemany("INSERT INTO Hoadon VALUES (?,?,?)", invoices)


# COALESCE dung de thay the gia tri neu = null thi se tra ve 0

query = """
SELECT sp.Tensp AS "Ten san pham",
       sp.Soluong AS "So luong nhap",
       COALESCE(SUM(hd.Soluong),0) AS "So luong ban",
       sp.Soluong - COALESCE(SUM(hd.Soluong),0) AS "So luong ton"
FROM Sanpham sp
LEFT JOIN Hoadon hd ON sp.Masp = hd.Masp
GROUP BY sp.Masp, sp.Tensp, sp.Soluong
"""

cursor.execute(query)

# fill data

rows = cursor.fetchall()
# print relsult
col1 = 13
col2 = 15
col3 = 14
col4 = 13

Tieude = f"| {'Ten san pham':<{col1}} | {'So luong nhap':<{col2}} | {'So luong ban':<{col3}} | {'So luong ton':<{col4}} |"

Dorong = f"| {'-' * col1}-|-{'-' * col2}-|-{'-' * col3}-|-{'-' * col4} |"

print(Tieude)
print(Dorong)

for tensp, nhap, ban, ton in rows:
    print(f"| {tensp:<{col1}} | {nhap:<{col2}} | {ban:<{col3}} | {ton:<{col4}} |")

conn.close()
