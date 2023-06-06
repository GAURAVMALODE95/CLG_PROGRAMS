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

def remove():
    set_sel = int(input("From which set do you want to delete an element? (1/2): "))
    del_ele = int(input("Enter the value to delete: "))

    if set_sel == 1:
        if del_ele in A:
            A.remove(del_ele)
            print("Element found in set A and deleted it!")
        else:
            print("Element not found in set A.")
            
    elif set_sel == 2:
        if del_ele in B:
            B.remove(del_ele)
            print("Element found in set B and deleted it!")
        else:
            print("Element not found in set B.")
            
    else:
        print("Invalid set selection.")

def set_difference(set1, set2):
    difference = []
    for element in set1:
        if element not in set2:
            difference.append(element)
    return difference
    
while True:
    ch=int(input("1.enter elements in first set\n2.enter element in second set\n3.union of two sets\n4.intersection to two sets\n5.remove elements\n6.diffrence\n7.exit\n"))
    if(ch==1):
        inp_a()
    if(ch==2):
        inp_b()
    if(ch==3):
        union()
    if(ch==4):
        intersection()
    if(ch==5):
        remove()
    if(ch==6):
        set_difference(A,B)
    if(ch==7):
        break