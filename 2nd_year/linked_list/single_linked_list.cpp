#include<iostream>
using namespace std;
struct node{
    int data;
   struct node *next;
};
int main(){
struct node *head=NULL;
head=(struct node *)malloc(sizeof(struct node));
head->data=12;
head->next=NULL;//our first node looking as following
/*
        ...............
        :  12 : NULL  :
        ...............     */

struct node *node1=NULL;
node1=(struct node *)malloc(sizeof(struct node));
node1->data=13;
node1->next=NULL;
head->next=node1;

}