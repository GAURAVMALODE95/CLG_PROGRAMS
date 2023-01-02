# selection sort.
array = []


def selection_sort(array):
    for i in range(len(array)):
        min = i
        for j in range(i+1, len(array)):
            if (array[j] < array[min]):
                min = j
        (array[i], array[min]) = (array[min], array[i])


def bubble_sort(array):
    for i in range(len(array)):
        for j in range(0, len(array)-i-1):
            if (array[j] > array[j+1]):
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp


def entry():
    n = int(input("ENTER THE TOTAL NUMBER OF STUDENTS : "))

    for i in range(n):
        a = float(input("please enter your percentage : "))
        array.append(a)
    return (array)


entry()  # calling entry function and inserting elements in an array.

selection = int(input("\n1.SELECTION SORT\n2.BUBBLE SORT\n"))
if (selection == 1):
    selection_sort(array)
    print("OUR TOPPERS : ")
    for i in range(5):
        res = array[::-1]
        print(res[i])


if (selection == 2):
    bubble_sort(array)
    print("OUR TOPPERS : ")
    for i in range(5):
        res = array[::-1]
        print(res[i])
