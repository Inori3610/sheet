import sqlite3

conn = sqlite3.connect(("QLNS.db"))

cursor = conn.cursor()

cursor.execute("""CREATE TABLE IF NOT EXISTS Chucvu(
                    Macv TEXT PRIMARY KEY,
                    Tencv TEXT,
                    Tienphucap INTEGER) """)

cursor.execute("""CREATE TABLE IF NOT EXISTS Nhanvien(
                    Manv TEXT PRIMARY KEY,
                    Hoten TEXT,
                    Ngaysinh TEXT,
                    Macv TEXT,
                    Luong INTEGER,
                    FOREIGN KEY (Macv) REFERENCES Chucvu(Macv))""")

chucvu = [
    ("CV1", "Giam doc", 120000),
    ("CV2", "Truong phong", 100000),
    ("CV3", "Pho phong", 80000),
    ("CV4", "Nhan vien", 50000),
    ("CV5", "Lao cong", 25000),
]

nhanvien = [
    ("NV1", "A", "12/4/1995", "CV1", 13000000),
    ("NV2", "B", "30/12/1997", "CV2", 12000000),
    ("NV3", "C", "23/6/2000", "CV3", 10000000),
    ("NV4", "D", "5/3/1996", "CV4", 7500000),
    ("NV5", "E", "4/7/1970", "CV5", 5000000),
]

cursor.executemany("INSERT INTO Chucvu VALUES (?,?,?)", chucvu)
cursor.executemany("INSERT INTO Nhanvien VALUES (?,?,?,?,?)", nhanvien)

query = """

SELECT nv.Manv AS "Ma nhan vien",
        nv.Hoten AS "Ho va ten",
        nv.Ngaysinh AS "Ngay sinh",
        nv.Luong AS "luong goc",
        nv.Luong + COALESCE(SUM(cv.Tienphucap),0) AS "Tong luong"
FROM Nhanvien nv
LEFT JOIN Chucvu cv ON nv.Macv = cv.Macv
GROUP BY nv.Manv, nv.Hoten,nv.Ngaysinh,nv.Luong
"""

cursor.execute(query)

rows = cursor.fetchall()

col1 = 15
col2 = 15
col3 = 15
col4 = 13
col5 = 13


tieude = f"| {'Ma nhan vien':<{col1}} | {'Ho ten':<{col2}} | {'Ngay sinh':<{col3}} | {'Luong goc':<{col4}} | {'Tong luong':<{col5}} |"

dorong = f"| {'-' * col1}-|-{'-' * col2}-|-{'-' * col3}-|-{'-' * col4}-|-{'-' * col5} |"

print(tieude)
print(dorong)

for Manv, Hoten, Ngaysinh, Luong, Tongluong in rows:
    print(
        f"| {Manv:<{col1}} | {Hoten:<{col2}} | {Ngaysinh:<{col3}} | {Luong:<{col4}} | {Tongluong:<{col5}} |"
    )

conn.close()
