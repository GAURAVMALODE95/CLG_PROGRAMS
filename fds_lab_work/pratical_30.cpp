#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> p1;
void insert()
{
    int x;
    cout << "enter the element : " << endl;
    cin >> x;
    p1.push(x);
}

void display(priority_queue<int> p1)
{
    cout << "the queue elements are : " << endl;
    while (!p1.empty())
    {
        cout << p1.top() << " ";
        p1.pop();
    }
}

void del()
{
    if (p1.empty())
    {
        cout << "queue already empty !" << endl;
    }
    else
    {
        cout << "element deleted : " << p1.top();
        p1.pop();
    }
}
int main()
{
    int c;
    char ch;
    cout << "\n\t****priority queue !" << endl;
    do
    {
        cout << "\n1.insert element.\n2.delete element\n3.display elements" << endl;
        cin >> c;

        switch (c)
        {
        case 1:
            insert();
            break;

        case 2:
            del();
            break;

        case 3:
            display(p1);
            break;
        }
        cout << "continue?(y/n)" << endl;
        cin >> ch;

    } while (ch != 'n');

    return 0;
}
