#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void count_nodes_in_linked_list(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        cout << "linked list is empty!!";
    }

    struct node *p = NULL;
    while (head != NULL)
    {
        count++;
        p = p->next;
    }
    cout << "TOTAL NUMBER OF NODES IN LINKED LIST IS : ";
}
int main()
{
    struct node *head, *p;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 21;
    head->next = NULL;
    p = head;
    for (int i = 0; i < 4; i++)
    {

        p->next = (struct node *)malloc(sizeof(struct node));
        cout << "ENTER THE VALUE OF DATA : ";
        int z;
        cin >> z;

        p->next->data = z;
        p->next->next = NULL;
        p = p->next;
    }
   

    count_nodes_in_linked_list(head);

    return 0;
}