def sentinal_search(array,target):
    size=len(array)
    array.append(target)
    i=0
    while(array[i]!=target):
        i=i+1
        if(i==size):
            return none
        else:
            return i

total_students=int(input("enter the total no of students : "))
array=[]
for i in range(total_students):
    array.append(int(input("enter the roll calls : ")))
key=int(input("enter key : "))
    
result=sentinal_search(array,key)
if(result!=1):
    print("student was present")
    
else:
    print("student was absent")
