def kt_so_hoan_hao(n):
    tong = 0
    for i in range(1,n):
        if (n%i)==0:
            tong += i
    if tong==n:
        return True
    else:
        return False
    
kt = int(input("Nhap vao mot so "))
if kt_so_hoan_hao(kt):
    print(f"{kt} la so hoan hao")
else:
    print(f"{kt} ko phai la so hoan hao")
    
    
    