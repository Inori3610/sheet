def so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


n = int(input("Nhap vao so cac so nguyen to : "))

so_hien_tai =2
dem=0
list =[]
while dem < n:
    so_hien_tai += 1
    if so_nguyen_to(so_hien_tai):
        list.append(so_hien_tai)
        dem += 1

print(f"{n} số nguyên tố: {list}")