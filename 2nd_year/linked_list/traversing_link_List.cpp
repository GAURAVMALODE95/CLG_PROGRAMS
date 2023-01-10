#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void count_of_nodes(struct node *head){
    int count=0;
    if(head== NULL){
        cout<<"linked list is empty !";
    }
    struct node *p = NULL;
    p=head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    cout<<"TOTAL NUMBERS OF NODES IN A LINKED LIST IS : "<<count;

}
int main(){
struct node *head=NULL;
head=(struct node *)malloc(sizeof(struct node));
head->data=12;
head->next=NULL;//our first node looking as following


struct node *node1=NULL;//creating second node
node1=(struct node *)malloc(sizeof(struct node));
node1->data=13;
node1->next=NULL;
head->next=node1;

struct node *node2=NULL;//creating third node
node2=(struct node *)malloc(sizeof(struct node));
node2->data=14;
node2->next=NULL;
node1->next=node2;


count_of_nodes(head);


}