'''Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client‘s telephone number. Make use of two collision
handling techniques and compare them using number of comparisons required to find
a set of telephone numbers'''

mob=[]
name=[]
index=[]
h_t=[]
for i in range(10):
    h_t.append(-1)
total_custo=int(input("enter the total no of customers : "))

def get_data():
    id=0
    for i in range(total_custo):
        id+=1
        x=input("enter the name of the customer : ")
        y=int(input("enter the 10 digit mobile number : "))
        while len(str(y))!=10:
            print("please recheck mobile number you have entered !")
            y=int(input("enter the 10 digit mobile number : "))
        mob.append(y)
        name.append(x)
        index.append(id)

def hash():
    for j in range(total_custo):
        z=mob[j]%10
        h_t[z]=mob[j]

def display():
    print("****************TELEPHONE DATA*****************")
    print("ID","\t","NAME","\t   ","MOBILE NO","\n")
    for i in range(total_custo):
        print(index[i],"\t",name[i],"\t",mob[i])

    print("********Hash Table**********")
    print("key","\t","mobile_no")
    for i in range(10):
        if h_t[i]!=-1:
          
            print(i,"\t",h_t[i])
get_data()
hash()
display()

