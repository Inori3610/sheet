# abtractionmethod la tu khoa
from abc import ABC, abstractmethod


class Employee(ABC):
    def __init__(self, name, base_salary):
        self.name = name
        self.base_salary = base_salary

    # tao ham truu tuong o lop cha
    @abstractmethod
    def caculate_salary(self):
        pass

    def display_info(self):
        print(f"Employee name : {self.name} | Base salary : {self.caculate_salary}")


# ke thua
class AdminStaff(Employee):
    def __init__(self, name, base_salary, position_allowance):
        super().__init__(name, base_salary)
        self.position_allowance = position_allowance

    # Override method o lop con
    def caculate_salary(self):
        return self.base_salary + self.position_allowance


admin1 = AdminStaff("Inori", 2000000, 3000000)
admin1.display_info()
