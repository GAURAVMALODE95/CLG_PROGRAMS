total_ammount = 0
print("(deposit) d-ammount")
print("(withdraw) w-ammount")


while True:
    a = input()
    ops = a.split(" ")
    operation = ops[0]
    ammount = int(ops[1])

    if (operation == "d"):
        total_ammount = ammount+total_ammount

    if (operation == "w"):
        if (ammount > total_ammount):
            print("\ninsufficient balance!!")
        else:
            total_ammount = total_ammount-ammount
    print("\nyour total balance is = ", total_ammount)

    a = input("\npress y for continew : ")
    if not (a == "y"):
        break


print("thank you sir for using our services you total balance is",total_ammount,"rs")
