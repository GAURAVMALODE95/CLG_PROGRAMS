#include <iostream>
#include <queue>
using namespace std;
queue<int> s1;

int add_data()
{
    int x;

    cout << "enter job data : " << endl;
    cin >> x;
    s1.push(x);
}

void delect()
{
    if (s1.empty())
    {
        cout << "queue is already empty!!!" << endl;
    }
    else
    {
        s1.pop();
    }
}


void display(queue<int> s1)
{
    cout << "jobs in the queue : " << endl;
    while (!s1.empty())
    {
        
        cout << s1.front() << endl;
        s1.pop();
    }
}
int main()
{
    //s1.push(-1);
    int ch;
    do
    {
        cout << "****hello sir*****" << endl;
        cout << "\n1.add job.\n2.delete job.\n3.display jobs.\n4.exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            add_data();
            break;
        case 2:
            delect();
            break;
        case 3:
            display(s1);
            break;
        case 4:
            break;
        }
    } while (ch != 4);
    return 0;
}
