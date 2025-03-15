from collections import deque

queue = deque([])

def addinfo():
    name = input("Enter name: ")
    age = int(input("Enter age: "))
    queue.append((name, age))
    
    
def displayinfo():
    if not queue:
        print("Queue is empty!")
    else:
        #print("Name\tAge")
        print("List name and age info")
        for name, age in queue:
            print(f"Name : {name}\t Age : {age}")
def popinfo():
    if not queue:
        print("Queue is empty!")
    else:
        first_item = queue.popleft()
        print(f"Removed name: {first_item[0]}, Age: {first_item[1]}")
        
    
addinfo()
addinfo()
displayinfo()
popinfo()
displayinfo()
