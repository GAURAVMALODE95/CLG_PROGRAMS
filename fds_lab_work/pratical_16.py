#QUICK SORT

def partition(array, low, high):

  
  pivot = array[high]

  
  i = low - 1

  
  for j in range(low, high):
    if array[j] <= pivot:
      
      i = i + 1

      
      (array[i], array[j]) = (array[j], array[i])

  
  (array[i + 1], array[high]) = (array[high], array[i + 1])

  
  return i + 1


def quickSort(array, low, high):
  if low < high:

    
    pi = partition(array, low, high)

    
    quickSort(array, low, pi - 1)

    quickSort(array, pi + 1, high)


array = []
n=int(input("ENTER THE NUMBER OF ELEMENTS IN A ARRAY : "))
for i in range(n):
    array.append(int(input("ENTER THE ELEMENTS : ")))
print("Unsorted Array :")
print(array)

size = len(array)

quickSort(array, 0, size - 1)
print("sorted array :")
print(array)
