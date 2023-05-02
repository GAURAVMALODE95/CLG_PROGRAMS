A=[]
B=[]
uni_set=[]
inter_set=[]
def inp_a():
    a=int(input("enter the total no of elements you want to enter in set a : "))
    for i in range(a):
        b=int(input("enter the element : "))
        if b not in A:
            A.append(b)
        else:
            pass
    print("SET:- A = ",A)
def inp_b():
    a=int(input("enter the total no of elements you want to enter in set a : "))
    for i in range(a):
        b=int(input("enter the element : "))
        if b not in B:
            B.append(b)
        else:
            pass
    print("SET:- B = ",B)



def union():
    uni_set=A
    uni_set.extend(x for x in B if x not in uni_set)
    print("union of set A and set B :- ",uni_set)

def intersection():
    inter_set=[i for i in A if i in B]
    print(inter_set)

    
while True:
    ch=int(input("1.enter elements in first set\n2.enter element in second set\n3.union of two sets\n4.intersection to two sets\n5.exit\n"))
    if(ch==1):
        inp_a()
    if(ch==2):
        inp_b()
    if(ch==3):
        union()
    if(ch==4):
        intersection()
    if(ch==5):
        break
    