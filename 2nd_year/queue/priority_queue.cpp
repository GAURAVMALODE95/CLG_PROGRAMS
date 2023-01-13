#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> s1;
vector<int> v1;
void insert_data()
{
    char ch;
    int x;
    cout << "enter the element : " << endl;
    cin >> x;
    v1.push_back(x);
}

void get()
{
    sort(v1.begin(), v1.end());
    for (int i : v1)
    {
        s1.push(i);
    }
}
void display_queue()
{
    while (!s1.empty())
    {

        cout << s1.front() << " ";
        s1.pop();
    }
}
void delete_ele()
{
    if (s1.empty())
    {
        cout << "the queue is already empty.";
    }
    else
    {
        cout << "deleted element : " << endl;
        s1.pop();
    }
}
int main()
{
    char ch;
    do
    {

        cout << "\n1.insert element.\n2.delete element\n3.display elements.\n4.exit";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert_data();
            get();
            break;
        case 2:
            delete_ele();
            break;

        case 3:
            display_queue();
            break;

        case 4:
            break;
        }
        
            
    }while (ch != 4);

    return 0;
}