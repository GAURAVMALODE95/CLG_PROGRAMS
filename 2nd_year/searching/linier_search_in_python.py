def linier_search(array,key):
    for i in range(a):
        if(array[i]==key):
            return i
    return -1

print("....**** hello sir ****....")
a=int(input("how many students were present for test : "))
array=[]
for i in range(a):
    b=int(input("enter the roll numbers of students : "))
    array.append(b)
print("roll numbers students who was present for test are : ")
print(array)

key=int(input("For which roll number you are searching : "))#takeing search key from user
d=int(input(print("you have entered search key as : ",key,"\n 1.linier search \n 2.binary search")))
if(d==1):
    c=linier_search(array,key)
    if(c==-1):
        print("roll number",key,"was absent for test...!")
    else:
        print("roll number",key,"was present for test....!")
if(d==2):
    print("coming soon")
