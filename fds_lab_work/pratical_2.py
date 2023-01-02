def average(a, b):
    sum = 0
    count = 0
    for i in range(b):
        if (a[i] != 0):
            sum += a[i]
            count = count+1
    print("average of the class is : ", sum/count)


def highest_score(a):
    for i in range(len(a)):
        max = a[0]
        break
    for i in range(1, len(a)):
        if (a[i] > max):
            max = a[i]
    return max


def lowest_score(a):
    for i in range(len(a)):
        min = a[0]
        break
    for i in range(1, len(a)):
        if (a[i] < min):
            min = a[i]
    return min


def absent(a):
    count = 0
    for i in range(len(a)):
        if (a[i] == -1):
            count = count+1
    print("total absent students : ", count)


'''def highest_frequency(a):
    z=[]
    x=[]
    for i in range(len(a)):
        z.append(a[i])
    for i in range(len(z)):
        if(a[i]==z[i]):
            
    print(x)'''


a = []
total_students = int(input("enter the total number of students : "))
for i in range(total_students):
    a.append(
        int(input("enter the marks of the student (for absent students enter -1): ")))


flag = 1
while (flag == 1):
    print("\n******hello sir****")
    ch = int(input("\n1.highest score of class\n2.lowest score of class\n3.total no of absent students\n4.average results of class "))

    if (ch == 1):
        print("highest score in class is : ", highest_score(a))

        q = input("want to continew ?(y/n)")
        if (q == 'y'):
            flag = 1
        else:
            flag = 0


    elif(ch==2):
        print("lowest score in class is : ", lowest_score(a))
        q = input("want to continew ?(y/n)")
        if (q == 'y'):
            flag = 1
        else:
            flag = 0


    elif(ch == 3):
        absent(a)
        q =input("want to continew ?(y/n)")
        if (q == 'y'):
            flag = 1
        else:
            flag = 0


    elif(ch == 4):
        average(a, total_students)
        q = input("want to continew ?(y/n)")
        if (q == 'y'):
            flag = 1
        else:
            flag = 0
