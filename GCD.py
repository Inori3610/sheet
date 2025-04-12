import math

def ucln(a,b):
    while b!=0:
        # Switch value a = b and b = a % b 
        a, b = b,a % b
    return a

a = int(input("Enter a : "))
b = int(input("Enter b : "))

print(f"GCD of {a} and {b} is : {ucln(a,b)} def")
print(f"GCD of {a} and {b} is : {math.gcd(a,b)} math") # math library