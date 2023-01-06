#bubble sort
def bubble(array):
    for i in range(len(array)):
        for j in range(0,len(array)-i-1):
            if(array[j]>array[j+1]):
                temp=array[j]
                array[j]=array[j+1]
                array[j+1]=temp






array=[]
n=int(input("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY : "))
for i in range(n):
    array.append(int(input("PLEASE ENTER THE VALUES : ")))
bubble(array)
print(array)
