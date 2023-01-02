#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class item
{
public:
    char name[10];
    int quantity;
    int cost;
    int code;
    bool operator==(const item &i1)
    {
        if (code == i1.code)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool operator<(const item &i1)
    {
        if (cost < i1.cost)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
vector<item> o1;
bool compare(const item &i1, const item &i2)
{
    return i1.cost < i2.cost;
}
void insert()
{
    item i1;
    cout << "enter item name : " << endl;
    cin >> i1.name;
    cout << "enter quantity : " << endl;
    cin >> i1.quantity;
    cout << "enter cost : " << endl;
    cin >> i1.cost;
    cout << "enter code : " << endl;
    cin >> i1.code;

    o1.push_back(i1);
}
void print(item &i1)
{
    cout << "\nitem name : " << i1.name;
    cout << "\nitem code : " << i1.code;
    cout << "\nitem cost : " << i1.cost;
    cout << "\nitem quantity : " << i1.quantity;
}
void display()
{
    for_each(o1.begin(), o1.end(), print);
}
void search()
{
    item i1;
    vector<item>::iterator p;
    int key;
    cout << "enter code to search : " << endl;
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "sorry sir product not found !" << endl;
    }
    else
    {
        cout << "product is avilable !" << endl;
    }
}
void dlt()
{
    item i1;
    vector<item>::iterator p;
    cout << "enter code to delete : " << endl;
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "sorry sir product not found for delecting !" << endl;
    }
    else
    {
        o1.erase(p);
        cout << "product is deleted !" << endl;
    }
}

int main()
{
    int ch;
    do
    {
        cout << " * * * * * * * * welcome * * * * * * * * " << endl;
        cout << "\n1.insert\n2.display\n3.search\n4.sort\n5.delete\n6.exit\nPLEASE ENTER YOUR CHOICE : " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(o1.begin(), o1.end(), compare);
            display();
            break;

        case 5:
            dlt();
            break;

        case 6:
            break;
        }
    } while (ch != 6);

    return 0;
}
