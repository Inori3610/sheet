def so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

n = int(input("Nhap vao so nguyen to can kiem tra"))

if (so_nguyen_to(n)):
    print(f"{n} la so nguyen to")
else:
    print(f"{n} ko phai la so nguyen to")
