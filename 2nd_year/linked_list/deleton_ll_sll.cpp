#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *next;
} sll;

struct node *delect_first(node *head){
    node *p;
    head=p;
    head=head->next;
    free(p);
    return head;
}
   void display(node *head)
{
    struct node *p;
    p = head;
    cout << "YOUR LINKED LIST IS :" << endl;
    while (p != NULL)
    {

        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{
    struct node *head = NULL;
    
    sll *node1 = NULL;
    struct node *node2 = NULL;


    head = (struct node *)malloc(sizeof(struct node));
    head->data = 14;
    head->next = node1;

    node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 12;
    node1->next = node2;

    node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 13;
    node2->next = NULL;


    delect_first(head);
    display(head);
}