import pickle


class Customer:
    def __init__(self):
        self.makh = ""
        self.tenkh = ""
        self.diachi = ""
        self.sdt = ""
        self.soluong = ""
        self.dongia = ""

    def input(self):
        print("--------------------INPUT----------------------")
        self.makh = input("Ma khach hang   : ")
        self.tenkh = input("Ten khach hang : ")
        self.diachi = input("Dia chi       : ")
        self.sdt = input("So dien thoai    : ")
        self.soluong = float(input("So luong     : "))
        self.dongia = float(input("Dongia        : "))

    def output(self):
        print("--------------------OUTPUT----------------------")
        print(f"Ma khach hang  : {self.makh}")
        print(f"Ten khach hang : {self.tenkh}")
        print(f"Dia chi        : {self.diachi}")
        print(f"So dien thoai  : {self.sdt}")
        print(f"So luong       : {self.soluong}")
        print(f"Don gia        : {self.dongia}")


class VIPcustomer(Customer):
    def __init__(self):
        super().__int__()
        self.chietkhau = ""

    def input(self):
        super().input()

        self.chietkhau = int(input("Chiet khau : "))

    def output(self):
        super().output()
        print(f"Chiet khau : {self.chietkhau}%")
        print(f"Tinh tien : {self.tinhtien()}")

    def tinhtien(self):
        return float((self.dongia * self.soluong)- ((self.dongia * self.soluong / 100)* self.chietkhau))


def ghi(name, dskh):
    with open(name, "wb") as f:
        pickle.dump(dskh, f)


def doc(name):
    with open(name, "rb") as f:
        return pickle.load(f)


def main():
    list = []
    tong_tien = 0.0

    n = int(input("Nhap vao so khach hang vip"))

    for i in range(n):
        vip = VIPcustomer()
        vip.input()
        list.append(vip)
    ghi("D:/Codetalker/Code/Python/python-cheat-sheet/OOP/danhsachkh.dat", list)

    print("Danh sach khach vip vua nhap la : ")

    dskh = doc("D:/Codetalker/Code/Python/python-cheat-sheet/OOP/danhsachkh.dat")
    for kh in dskh:
        kh.output()
        tong_tien += kh.tinhtien()
        print("-" * 40)

    print(f"Tong doanh thu : {tong_tien}")


main()

