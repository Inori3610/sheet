list = []


class BankAccount:
    def __init__(self, owner, balance, account_type):
        self.owner = owner
        self.balance = balance
        self.account_type = account_type

    # @abstractmethod
    def monthly_update(self):
        print(f"owner : {self.owner} | Balance : {self.balance}")

    def get_accout_type(self):
        return self.account_type


class SavingAccount(BankAccount):
    def __init__(self, owner, balance, account_type):
        super().__init__(owner, balance, account_type)

    def monthly_update(self):
        super().monthly_update()
        self.balance = self.balance + self.balance * 0.6
        print(f"owner : {self.owner} | Balance : {self.balance}")

    def get_accout_type(self):
        return self.account_type


class CheckingAccount(BankAccount):
    def __init__(self, owner, balance, account_type):
        super().__init__(owner, balance, account_type)

    def monthly_update(self):
        super().monthly_update()
        self.balance = self.balance - 5000
        print(f"owner : {self.owner} | Balance : {self.balance}")

    def get_accout_type(self):
        return self.account_type


class BusinessAccount(BankAccount):
    def __init__(self, owner, balance, account_type):
        super().__init__(owner, balance, account_type)

    def monthly_update(self):
        print("Business Account monthly_update : ")
        super().monthly_update()
        if self.balance < 10000:
            self.balance -= self.balance * 0.6
            print(f"owner : {self.owner} | Balance : {self.balance}")
        else:
            self.balance += self.balance * 0.6
            print(f"owner : {self.owner} | Balance : {self.balance}")

    def get_accout_type(self):
        return self.account_type


def main():
    loop = True
    choice = 0
    while loop:
        print("Menu")
        print("1. them danh sach")
        print("2. hien thi theo so du")
        print("3. hien thi theo SavingAccount : ")
        print("4. hien thi theo CheckingAccount : ")
        print("5. hien thi theo BusinessAccount")
        choice = int(input("Nhap lua chon : "))
        match choice:
            case 1:
                n = int(input("Nhap vao danh sack tai khoan : "))
                for i in range(n):
                    owner = input("Nhap vao ten chu so huu : ")
                    balance = float(input("Nhap vao so du : "))
                    account_type = input("Nhap vao loai tai khoan : ")
                    if account_type == "Saving":
                        bank_acc = SavingAccount(owner, balance, account_type)
                    elif account_type == "Checking":
                        bank_acc = CheckingAccount(owner, balance, account_type)
                    elif account_type == "Business":
                        bank_acc = BusinessAccount(owner, balance, account_type)
                    list.append(bank_acc)
            case 2:
                for i in range(len(list)):
                    list[i].monthly_update()
            case 3:
                for i in range(len(list)):
                    if list[i].get_accout_type == "Saving":
                        list[i].monthly_update()
                    else:
                        print("No SavingAccount")
            case 4:
                for i in range(len(list)):
                    if list[i].get_accout_type == "Checking":
                        list[i].monthly_update()
                    else:
                        print("No CheckingAccount")
            case 5:
                for i in range(len(list)):
                    if list[i].get_accout_type == "Business":
                        list[i].monthly_update()
                    else:
                        print("No BusinessAccount")
            case _:
                loop = False


main()
