list_n = list(map(int,input("Nhap vao 1 mang cac so nguyen : ").split()))
tong = 0

print(f"Mang vua nhap :{list_n}")
for i in list_n:
    if i % 2 == 0:
        tong += i

print(f"Tong cac so trong mang vua nhap la : {tong}")


# T_T
