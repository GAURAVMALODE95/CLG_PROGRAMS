
def linier_search(array,key): 
     for i in range(a): 
         if(array[i]==key): 
             return i 
     return -1 
  
def binary_search(array,a,key): 
    start=0 
    end=len(array)-1
    mid=0
    while(start<=end): 
        mid=(start+end)//2 
        if(array[mid]==key): 
            return mid
        if(key>array[mid]): 
             start=mid+1 
        else: 
             end=mid-1 
    print(mid)
    return -1
    
    

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
  
  
  
print("....**** hello sir ****....") 
a=int(input("how many students were present for test : ")) 
array=[] 
for i in range(a): 
    b=int(input("enter the roll numbers of students : ")) 
    array.append(b) 
print("roll numbers students who was present for test are : ") 
print(array) 
  
key=int(input("For which roll number you are searching : "))#takeing search key from user 
d=int(input(print("you have entered search key as : ",key,"\n 1.linier search \n 2.binary search\n3.sentinal search"))) 
if(d==1): 
    c=linier_search(array,key) 
    if(c==-1): 
        print("roll number",key,"was absent for test...!") 
    else: 
        print("roll number",key,"was present for test....!") 
if(d==2): 
    res=binary_search(array,a,key)
    if(res!=-1):
        print("student was present")
    else:
        print("student was absent")
        

if(d==3): 
    rees=sentinal_search(array,key)
    if(rees!=1):
        print("student was present")
    else:
        print("student was absent")
