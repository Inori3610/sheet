print("Day so fibonacci")
n = int(input("Nhap vao 1 so nguyen : "))
dayso =[]
i = 0
while i <= n:
    if i == 0:
        dayso.append(0)
    elif i == 1:
        dayso.append(1)
    else:
        dayso.append(dayso[i-1] + dayso[i-2])
    i += 1
dayso.pop(0)
print(f"Day so fibonacci {dayso}")
print(f"So fibonacci nho nhat : {dayso[0]}")
print(f"So fibonacci lon nhat : {dayso[n-1]}")