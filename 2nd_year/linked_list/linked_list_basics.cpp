/*
linked list madeup of collection of nodes.
single node shows an data and contains adress of next node.
        ....................
        :   data :  next    :
        ....................
this is dynamic data stuture.no memory wastage.
delection is easy.no shift needed.
types:
1)singly linked list.
2)double linked list
3)circular linked list
-----******single node shows an data and contains adress of next node.-----******
*/
//let us create a single node of the linked list

#include<iostream>
using namespace std;
struct node{
    int data;
   struct node *next;//contain adress
};
int main(){
struct node *head = NULL;
head=(struct node *)malloc(sizeof(struct node));
int x;
cout<<"enter the data in a node";
cin>>x;
head->data=x;
head->next=NULL;//no adress as it is single node
cout<<head->data;//will print 45
return 0;

}






