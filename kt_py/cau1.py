list_n = list(input("Nhap vao 1 mang cac so nguyen : ").split())
tong = 0

mang = [9, 2, 6]
print(f"Mang vua nhap :{mang}")
for i in mang:
    if i % 2 == 0:
        tong += i

print(f"Tong cac so trong mang vua nhap la : {tong}")


# T_T
