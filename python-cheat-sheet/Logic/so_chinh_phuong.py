import math

def kt_so_chnh_phuong(n):
    
    temp = int(math.sqrt(n))
    if (temp * temp)==n:
        return True
    else:
        return False

list = []

n = int(input("Nhap vao mot so "))
if kt_so_chnh_phuong(n):
    print(f"{n} la so chinh phuong")
else :
    print(f"{n} ko phai la so chnh phuong")
    
for i in range(1,n+1):
    if kt_so_chnh_phuong(i):
        list.append(i)

print(f"Day so chinh huong be <= {n} : {list}")
