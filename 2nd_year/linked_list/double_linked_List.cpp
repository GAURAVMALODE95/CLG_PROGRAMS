#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr;

    while(ptr!=head){
    cout<<ptr->data<<endl;
    ptr = ptr->next;
}
}
int main(){
 struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    linkedListTraversal(head);
return 0;
}