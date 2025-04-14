def count_unique_characters(s):
    s = s.lower()
    unique_characters = set(s)

    unique_characters.discard(" ")  # Loại bỏ khoảng trắng (nếu cần)
    
    return unique_characters, len(unique_characters)

string = "Heelo World"
print("Số lượng ký tự khác nhau:", count_unique_characters(string))
