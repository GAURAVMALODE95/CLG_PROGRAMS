#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} sll;
struct node *head = NULL;
struct node *add_beg(int d)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(sll));
    new_node->data = d;
    new_node->next = head;
    head = new_node;
};
void search(node *head,int elem){
    node *p;
    head=p;
    while(p->next!=NULL){
        p=p->next;
        if(p->data==elem){
            cout<<"found"<<endl;
        }
        
    }
}
void display()
{
    struct node*  p;
    p = head;
    cout<<"YOUR LINKED LIST IS :"<<endl;
    while (p != NULL)
    {
        
        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{
   

    add_beg(123);
    add_beg(124);
    add_beg(125);
    add_beg(126);
    add_beg(127);
    add_beg(128);
    add_beg(129);
    search(head,126);
    display();

    return 0;
}
