table_size=10
linear_probing_table = [None] * table_size
double_hashing_table = [None] * table_size

def input_record():
    name = input("Enter Name: ")
    while True:
        try:
            number = int(input("Enter Number (a 10-digit integer): "))
            if len(str(number)) != 10:
                raise ValueError
            break
        except ValueError:
            print("Invalid input. Please enter a valid 10-digit integer.")
    return (name, number)


def linear_probing_insert(record):
    index = hash(record[1]) % table_size
    while linear_probing_table[index] is not None:
        index = (index + 1) % table_size
    linear_probing_table[index] = record

def linear_probing_search(record):
    index = hash(record[1]) % table_size
    while linear_probing_table[index] is not None:
        if linear_probing_table[index][1] == record[1]:
            return index
        index = (index + 1) % table_size
    return -1

def linear_probing_display():
    print("Linear Probing Table:")
    for i in range(table_size):
        if linear_probing_table[i] is not None:
            print(f"Index {i}: {linear_probing_table[i]}")
        else:
            print(f"Index {i}: Empty")

def double_hashing_insert(record):
    index = hash(record[1]) % table_size
    offset = 1
    while double_hashing_table[index] is not None:
        index = (index + offset) % table_size
        offset += 1
    double_hashing_table[index] = record

def double_hashing_search(record):
    index = hash(record[1]) % table_size
    offset = 1
    while double_hashing_table[index] is not None:
        if double_hashing_table[index][1] == record[1]:
            return index
        index = (index + offset) % table_size
        offset += 1
    return -1

def double_hashing_display():
    print("Double Hashing Table:")
    for i in range(table_size):
        if double_hashing_table[i] is not None:
            print(f"Index {i}: {double_hashing_table[i]}")
        else:
            print(f"Index {i}: Empty")

# Rest of the code remains the same


choice1 = 0
while choice1 != 3:
    print("************************")
    print("1. Linear Probing")
    print("2. Double Hashing")
    print("3. Exit")
    print("************************")

    choice1 = int(input("Enter Choice: "))
    if choice1 > 3:
        print("Please Enter Valid Choice")

    if choice1 == 1:
        linear_probing_table = [None] * table_size
        choice2 = 0
        while choice2 != 4:
            print("************************")
            print("1. Insert")
            print("2. Search")
            print("3. Display")
            print("4. Back")
            print("************************")

            choice2 = int(input("Enter Choice: "))
            if choice2 > 4:
                print("Please Enter Valid Choice")

            if choice2 == 1:
                record = input_record()
                linear_probing_insert(record)

            elif choice2 == 2:
                record = input_record()
                position = linear_probing_search(record)
                if position != -1:
                    print(f"Record found at index {position}")
                else:
                    print("Record not found")

            elif choice2 == 3:
                linear_probing_display()

    elif choice1 == 2:
        double_hashing_table = [None] * table_size
        choice2 = 0
        while choice2 != 4:
            print("************************")
            print("1. Insert")
            print("2. Search")
            print("3. Display")
            print("4. Back")
            print("************************")

            choice2 = int(input("Enter Choice: "))
            if choice2 > 4:
                print("Please Enter Valid Choice")

            if choice2 == 1:
                record = input_record()
                double_hashing_insert(record)

            elif choice2 == 2:
                record = input_record()
                position = double_hashing_search(record)
                if position != -1:
                    print(f"Record found at index {position}")
                else:
                    print("Record not found")

            elif choice2 == 3:
                double_hashing_display()
