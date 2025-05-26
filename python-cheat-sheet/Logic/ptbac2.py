import math

a = float(input("Nhap a : "))
b = float(input("Nhap b : "))
c = float(input("Nhap c : "))

delta = pow(b,2)-4*a*c

if (delta < 0):
    print("Phuong trinh vo nghiem")
elif (delta == 0):
    print(f"Phuong trinh tren co nghiem kep x1=x2={-b/2*a}")
else:
    print(f"Phuong trinh co 2 nghiem phan biet x1 = {-b+math.sqrt(delta)/2*a} , x2 = {-b-math.sqrt(delta)/2*a}")
    
    