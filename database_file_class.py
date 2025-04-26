import pickle


class Hocsinh:
    def __init__(self):
        self.ho_ten = ""
        self.ngay_sinh = ""
        self.diem_toan = 0.0
        self.diem_van = 0.0

    def input(self):
        print("--------------------------INPUT----------------------------")
        self.ho_ten = input("Ho ten : ")
        self.ngay_sinh = input("Ngay sinh : ")
        self.diem_toan = float(input("Diem toan : "))
        self.diem_van = float(input("Diem van : "))

    def output(self):
        print("------------------------OUTPUT----------------------------")
        print(f"Ho va ten : {self.ho_ten}")
        print(f"Ngay sinh : {self.ngay_sinh}")
        print(f"Diem toan : {self.diem_toan}")
        print(f"Diem van  : {self.diem_van}")


class HocSinhChuyenVan(Hocsinh):
    def __init__(self):
        super().__init__()
        self.lop = ""

    def input(self):
        super().input()
        self.lop = input("Lop : ")

    def output(self):
        super().output()
        print(f"Lop      : {self.lop}")
        print(f"Diem TB  : {self.diemTB():.2f}")
        print(f"Xep loai : {self.xeploai()}")

    def diemTB(self):
        return (self.diem_toan + self.diem_van * 2) / 3

    def xeploai(self):
        if self.diemTB() < 5:
            return "Kem"
        elif self.diemTB() < 6.5:
            return "Tb"
        elif self.diemTB() < 7.5:
            return "Kha"
        elif self.diemTB() < 9:
            return "Gioi"
        elif self.diemTB() < 10:
            return "Xuat xac"


class HocSinhChuyenToan(Hocsinh):
    def __init__(self):
        super().__init__()
        self.lop = ""

    def input(self):
        super().input()
        self.lop = input("Lop : ")

    def output(self):
        super().output()
        print(f"Lop      : {self.lop}")
        print(f"Diem TB  : {self.diemTB()}")
        print(f"Xep loai : {self.xeploai()}")

    def diemTB(self):
        return (self.diem_toan * 2 + self.diem_van) / 3


def ghi(name, dssv):
    with open(name, "wb") as f:
        pickle.dump(dssv, f)


def doc(name):
    with open(name, "rb") as f:
        return pickle.load(f)


def main():
    danhsach = []
    n = int(input("Nhap vao so hoc sinh chuyen van : "))
    for i in range(n):
        print(f"\n -- Nhap thong tin hoc sinh thu {i + i} -- ")
        hs = HocSinhChuyenVan()
        hs.input()
        danhsach.append(hs)
    ghi("/home/inori/Documents/Code/Python/class_file/danhsach.dat", danhsach)

    print("\n Danh sach hoc sinh da ghi vao tep")

    dssv = doc("/home/inori/Documents/Code/Python/class_file/danhsach.dat")

    for hs in dssv:
        if hs.xeploai() in ["Gioi", "Xuat xac"]:
            hs.output()
            print("-" * 40)


if __name__ == "__main__":
    main()
