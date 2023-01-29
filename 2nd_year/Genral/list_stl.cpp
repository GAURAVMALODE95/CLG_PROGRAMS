#include <iostream>
#include <list>
#include <string>
using namespace std;
list<int, string> l1;
class node
{
public:
    int prn;
    char name[20];
    node *next;
};
void new_president(list<int, string> l1)
{
    node n1;
    cout << "enter the president prn : " << endl;
    cin >> n1.prn;
    cout << "enter president name : " << endl;
    cin >> n1.name;
    l1.push_back(n1);
}
int main()
{
    new_president();

    return 0;
}