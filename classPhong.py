list = []

class Phong:
    def __init__ (self, tenphong, giaphong):
        self.tenphong = tenphong
        self.giaphong = giaphong
    
    def tinh_tien(self, songay):
        return self.giaphong * songay

class Thuephong(Phong):
    def __init__(self, tenphong, giaphong, tenkhachhang,loaiphong,songay):
        super().__init__(tenphong, giaphong)
        self.tenkhachhang = tenkhachhang
        self.loaiphong = loaiphong
        self.songay = songay
    def tinh_tien(self, songay):
        if self.loaiphong == "VIP" or self.loaiphong == "vip" or self.loaiphong == "Vip":
            return super().tinh_tien(songay) * 1.1
        else:
            return super().tinh_tien(songay)
        
    def display(self):
        print("------------------THONG TIN THUE PHONG-------------------")
        print(f"Phong: {self.tenphong}")
        print(f"Gia phong: {self.giaphong}")
        print(f"Ten khach hang: {self.tenkhachhang}")
        print(f"Loai phong: {self.loaiphong}")
        print(f"Thoi gian thue: {self.songay} ngay")
        print(f"Thanh tien: {self.tinh_tien(self.songay)}")
        print(f"Tong tien thue phong: {self.tinh_tien(self.songay)}")
        
    def input(self):
        print("---------------NHAP THONG TIN THUE PHONG----------------")
        self.tenphong = input("Nhap ten phong: ")
        self.giaphong = int(input("Nhap gia phong: "))
        self.tenkhachhang = input("Nhap ten khach hang: ")
        self.loaiphong = input("Nhap loai phong: ")
        self.songay = int(input("Nhap so ngay thue: "))
        list.append(self)
        self.display()
    
    def update(tenkhachhang, new_data):
        for customer in list:
            if customer.tenkhachhang == tenkhachhang:
                customer.tenkhachhang = new_data[0]
                customer.loaiphong = new_data[1]
                customer.songay = new_data[2]
                print(f"Updated {tenkhachhang} to {new_data}")
                return
    def delete(tenkhachhang):
        for customer in list:
            if customer.tenkhachhang == tenkhachhang:
                list.remove(customer)
                print(f"Deleted {tenkhachhang}")
                return
        print(f"{tenkhachhang} not found")
            
        
        
    
def main():
    loop = True
    choice = 0;
    while loop:
        print("---------------QUAN LY THUE PHONG----------------")
        print("1. Nhap so luong khach hang thue phong")
        print("2. Nhap 1 Khach hang thue phong moi")
        print("3. Thong tin khach hang thue phong")
        print("4. Sua thong tin khach hang thue phong")
        print("5. Xoa thong tin khach hang thue phong")
        print("6. Thoat")
        choice = int(input("Nhap lua chon: "))
        match choice:
            case 1:
                n = int(input("Nhap so luong khach hang thue phong: "))
                print(f"Da nhap {n} khach hang thue phong")
                for i in range(n):
                    thuephong = Thuephong("",0,"","",0)
                    thuephong.input()
            case 2:
                thuephong = Thuephong("",0,"","",0)
                thuephong.input()
            case 3:
                if len(list) == 0:
                    print("Chua co khach hang thue phong nao!")
                else:
                    print("------------------THONG TIN KHACH HANG THUE PHONG-------------------")
                    for i in range(len(list)):
                        list[i].display()
            case 4:
                if len(list) == 0:
                    print("Chua co khach hang thue phong nao!")
                else:
                    tenkhachhang = input("Nhap ten khach hang can sua: ")
                    new_data = []
                    new_data.append(input("Nhap ten khach hang moi: "))
                    new_data.append(input("Nhap loai phong moi: "))
                    new_data.append(int(input("Nhap so ngay thue moi: ")))
                    Thuephong.update(tenkhachhang, new_data)
            case 5:
                if len(list) == 0:
                    print("Chua co khach hang thue phong nao!")
                else:
                    tenkhachhang = input("Nhap ten khach hang can xoa: ")
                    Thuephong.delete(tenkhachhang)
            case 6:
                loop = False
            case _:
                print("Lua chon khong hop le!")
                continue
                    
main()