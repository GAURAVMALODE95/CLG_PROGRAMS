//array elements should be in asscending or dec order
// mid elem=(start elem+end elem/2)

#include<iostream>
using namespace std;

/*int binary(int arr[],int size,int key){
    int start=0;
    int end=size-1;

    int mid=(start+end)/2;

    while(start<=end){
        if(arr[mid]==key){
            cout<<"key found ! ! ! ";
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
            }

        mid=(start+end)/2;
    
    break;}
    cout<<"key not found";

};



int main(){
int arr[5]={1,2,3,4,5};
int key;
cout<<"enter the search key";
cin>>key;
binary(arr,5,key);




return 0;    
}*/

int binary(int array[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(array[mid]==key){
            cout<<"element found! ! !";
        }
        if(key>array[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
        break;  
    }
    cout<<"element not found! ! !";
};








int main(){
    int array[10]={1,3,5,7,9,13,15,17,19,21};
    int key;
    cout<<"enter the search key";
    cin>>key;
    binary(array,10,key);





}