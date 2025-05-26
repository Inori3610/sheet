
number = list(map(int, input("Enter list number: ").split()))
s_number = int(input("Enter S number: "))
print("List number: ", number)

pair = []
for i in range(len(number)):
    for j in range(i+1, len(number)):
        if number[i] + number[j] == s_number:
            print(f"Pair found: {number[i]}, {number[j]}")
            pair.append((number[i], number[j]))

if pair:
    print(f"List all pair found = {s_number}: ")
    for p in pair:
        print(p)
else:
    print("No pairs found")

            