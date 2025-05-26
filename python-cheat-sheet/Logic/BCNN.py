import math

def bcnn(a, b):
    return abs(a * b) // math.gcd(a, b)

a = int(input("Nhap a : "))
b = int(input("Nhap b : "))

print(f"BCNN cua {a} va {b} la : {bcnn(a,b)}")

 