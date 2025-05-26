def ghi_so_chan(mang, ten_tep="/home/inori/Documents/Code/Python/so_chan.txt"):
    so_chan = ""
    with open(ten_tep, "w", encoding="utf-8") as file:
        for so in mang:
            if int(so) % 2 == 0:
                so_chan += so + " "
                file.write(so_chan)
        print(" Da ghi cac so chan vao trong tep")


mang = ["1", "2", "3", "4"]
ten_file = "/home/inori/Documents/Code/Python/so_chan.txt"


def tinh_tong_so_chan(ten_tep="/home/inori/Documents/Code/Python/so_chan.txt"):
    tong = 0
    with open(ten_tep, "r", encoding="utf-8") as file:
        content = file.read().strip()
        if content:
            for num in content.split():
                tong = tong + int(num)
            print(f"Noi dung tep : {content}")
            print(f"tong cac so chan : {tong}")
        else:
            print("Tep khong co so chan")


ghi_so_chan(mang, ten_file)
tinh_tong_so_chan(ten_file)
