#include <iostream>
using namespace std;


typedef struct node
{
    int data;
    node *next;
} sll;



struct node *delete_first(struct node *head)
{
    sll *p;
    p = head;
    head = head->next;
    free(p);
    return head;
}



struct node *delete_last(struct node *head)
{
    sll *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}




struct node *delete_any_pos(struct node *head, int index)
{
    sll *p, *q;
    p = head;
    q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
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

    struct node *node3 = NULL;
    node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 15;
    node3->next = NULL;
    node2->next = node3;

    head = delete_first(head); // sucessfullllyyyy ruuuunnnn......
    //delete_last(head);         // sucessfull......!
   // delete_any_pos(head, 2);   // sucessfulllllll......!!!!
    display(head);

    return 0;
}