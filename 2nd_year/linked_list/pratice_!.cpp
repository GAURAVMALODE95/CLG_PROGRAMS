// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef struct node{
    int data;
    node* next;
}s1;
struct node *head=NULL;
struct node *insert_at_start(int data){
    struct node *p=NULL;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=head;
    head=p;
    return(head);

}
struct node *insert_at_end(int data){
    struct node *p,*q;

    p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    head=q;
    while(q->next!=NULL){
        q=q->next;

    }q->next=p;

    

}

void at_any_position(struct node *head, int ser,int data)
{
    s1 *p, *q, *n;
    n=(struct node *)malloc(sizeof(s1));
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




void display(node* head)
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

int main() {


    insert_at_start(12);
    insert_at_start(16);
    insert_at_end(13);
    at_any_position(head,1,44);
    display(head);

    return 0;
}