import math

def kt_so_chnh_phuong(n):
    
    temp = int(math.sqrt(n))
    if (temp * temp)==n:
        return True
    else:
        return False

def kt_fibonacci(n):
    if kt_so_chnh_phuong(5*pow(n,2) + 4) or kt_so_chnh_phuong(5*pow(n,2) - 4):
        return True
    else:
        return False
    
list = []    

n = int(input("Nhap vao mot so : "))
if kt_fibonacci(n):
    print(f"{n} la so fibonacci")
else :
    print(f"{n} ko phai la so fibonacci")
    
for i in range(0,n):
    if kt_fibonacci(i):
        if i == 1:
            list.append(i)
        list.append(i)
print(f"Day so fibonacci <= {n} : {list}")
    
    