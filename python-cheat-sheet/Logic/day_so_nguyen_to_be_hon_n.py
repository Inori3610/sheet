def so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

list =[]
n = int(input("Nhap vao so cac so nguyen to"))

for i in range(n):
    if (so_nguyen_to(i)):
	    list.append(i)

print(f"Day so cac so nguyen to be hon {n} : ")
print(list)