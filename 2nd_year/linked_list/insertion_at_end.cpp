#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}sll;
void add_at_end(sll *head,int data)
{
    sll *p,*temp;
    p=head;
    temp=(struct node *)malloc(sizeof(sll));
    temp->data=data;
    temp->next=NULL;

    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
}

void display(struct node *head)
{
    sll *p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
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

  add_at_end(head,115);
  display(head);


return 0;
}