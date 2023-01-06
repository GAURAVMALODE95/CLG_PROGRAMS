def selection(array):
    for i in range(len(array)):
        min_index=i
        for j in range(i+1,len(array)):
            if(array[j]<array[min_index]):
                min_index=j
        (array[i],array[min_index])=(array[min_index],array[i])
    
    
array=[]
a=int(input("HOW MANY ELEMENTS ARE THERE IN ARRAY ? "))
for i in range(a):
    array.append(int(input("kindely enter the elements : ")))
    
selection(array)    
print("your sorted array : ")
print(array)
