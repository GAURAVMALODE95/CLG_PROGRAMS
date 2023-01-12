#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> s1;

    s1.push(21); // inserts an element at the back of the queue
    s1.push(24);
    s1.push(23);
    s1.push(22);
   // s1.pop(); // pops the element
    cout << "size of queue is : " << s1.size() << endl;
    cout<<"front of queue is : "<<s1.front()<<endl;

    // checking empty or not
    if (s1.empty())
    {
        cout << "queue is empty!!! " << endl;
    }
    else
    {
        cout << "queue is not empty!!!" << endl;
    }
    return 0;
}