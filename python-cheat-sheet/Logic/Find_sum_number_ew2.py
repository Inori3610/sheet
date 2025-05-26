list = []


def find(n):
    while n > 0:
        if n % 10 == 2:
            list.append(n)
        n -= 1


n = int(input("Enter n : "))
find(n)
print(f"List number < {n} and has the end = 2 ")
print(list)
