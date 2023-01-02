#we are performing operations on matrix.

def display_matrix1(x):#function to display matrix1
    for i in range(col1):
        for j in range(row1):
            print(matrix1[i][j],end=" ")
        print()
        
def display_matrix2(x):#function to display matrix2
    for i in range(col2):
        for j in range(row2):
            print(matrix2[i][j],end=" ")
        print()


def add(matrix1,matrix2):#function to add the matrix
    matrix=[]
    for i in range(len(matrix1)):
        a=[]
        for j in range(len(matrix1[i])):
            ele=matrix1[i][j]+matrix2[i][j]#adding with help of rows and coloums 
            a.append(ele)
        matrix.append(a)
    print(matrix)

def sub(matrix1,matrix2):#function to sub the matrix
    matrix=[]
    for i in range(len(matrix1)):
        a=[]
        for j in range(len(matrix1[i])):
            ele=matrix1[i][j]-matrix2[i][j]
            a.append(ele)
        matrix.append(a)
    print(matrix)

def mult(matrix1,matrix2):#function for multiplication of matrix
    matrix=[]
    for i in range(len(matrix1)):
        a=[]
        for j in range(len(matrix2[0])):
            elem=0
            for k in range(len(matrix2)):
                elem+=matrix1[i][k]*matrix2[k][j]
            a.append(elem)
        matrix.append(a)
    print(matrix)



def trans(matrix1):#function to transpose a matrix
    trans=[]
    for i in range(len(matrix1[0])):
        a=[]
        for j in range(len(matrix1)):
            elem=matrix1[j][i]#just interchanging the rows with the coloums
            a.append(elem)
        trans.append(a)
    print(trans)


#takeing input for first matrix
row1=int(input("enter the number of rows"))
col1=int(input("enter the number of coloums"))
matrix1=[]
for i in range(row1):
    a=[]
    for j in range(col1):
        a.append(int(input("enter the elements")))
    matrix1.append(a)

#takeing input for second matrix

row2=int(input("enter the number of rows"))
col2=int(input("enter the number of coloums"))
matrix2=[]
for i in range(row2):
    b=[]
    for j in range(col2):
        b.append(int(input("enter the elements")))
    matrix2.append(b)

#calling functions

print("your first matrix is")
display_matrix1(matrix1)
print("your second matrix is")
display_matrix2(matrix2)
print("addition of two matrices are")
add(matrix1,matrix2)
print("substraction of two matrices are")
sub(matrix1,matrix2)
print("transpose of matrix 1 is")
trans(matrix1)
print("transpose of matrix 2 is")
trans(matrix2)
print("multiplication of matrices is")
mult(matrix1,matrix2)
