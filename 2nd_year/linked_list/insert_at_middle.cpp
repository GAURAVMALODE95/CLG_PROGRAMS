#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} sll;


void at_any_position(struct node *head, int ser,int data)
{
    sll *p, *q, *n;
    n=(struct node *)malloc(sizeof(sll));
    n->data=data;
    n->next=NULL;
    p = head;
    

    while (p != NULL)
    {
        if (p->data == ser)
        {
            goto l1;
        }
        else
        {
            p = p->next;
        }
    }

l1:
    q = p->next;
    n->next = q;
    p->next = n;
}



void display(struct node *head)
{
    sll *p;
    p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{

    sll *head = NULL;
    head = (struct node *)malloc(sizeof(sll));
    head->data = 12;
    head->next = NULL;

    struct node *node1 = NULL;
    node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 13;
    node1->next = NULL;
    head->next = node1;

    struct node *node2 = NULL;
    node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 14;
    node2->next = NULL;
    node1->next = node2;
  
  
    display(head);
  at_any_position(head,3,122);
    
    
    return 0;
}