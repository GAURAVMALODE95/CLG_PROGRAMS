#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    queue()
    {
        size = 100;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {

            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int front()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            cout << "front  : " << arr[front];
        }
    }
    bool isempty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{

    return 0;
}