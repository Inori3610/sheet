def is_palindrome_number(n):
    # Step 1: Break the number into its digits and store in an array
    digits = []
    while n > 0:
        digits.append(n % 10)  # Extract the last digit
        n = n // 10  # Remove the last digit from n
    
    # Step 2: Check if the number is a palindrome by comparing digits
    for i in range(len(digits) // 2):
        if digits[i] != digits[len(digits) - i - 1]:
            return False  # Not a palindrome
    
    return True  # It's a palindrome

n = int(input("Nhap so: "))
if is_palindrome_number(n):
    print(f"{n} la so doi xung")
else:
    print(f"{n} khong phai la so doi xung")
