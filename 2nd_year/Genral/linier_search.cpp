#include <iostream>
using namespace std;

//program for displaying simple array

/*int main(){
    int arr[10]={1,2,55,34,65,84,75,1,423};

for(int i=0;i<10;i++){
    cout<<"arr["<<i<<"]="<<arr[i]<<endl;
}
}*/
//*****************--------------------*******************
//for find element by takeing search key as an input

/*bool search(int arr[],int size,int key){//function for searching
for(int i=0;i<size;i++){
    if(arr[i]==key){
        return 1;//returns true..
        }
}return 0;//returns false
}
int main(){
int n;
cin>>n;
int arr[10]={1,2,3,4,5,6,7,8,9};
bool ans=search(arr,10,n);
if(ans==1){
    cout<<"key is present";}
if(ans==0){
    cout<<"key is not present";
}
}*/
//***************--------------------------****************************
/*int main(){//program which gives us a location of search key
int key;
cin>>key;
int arr[10]={1,3,6,8,10,12,14,16,18,20};
for(int i=0;i<10;i++){
    if(arr[i]==key){
        cout<<"arr["<<i<<"]="<<arr[i];
    }}}*/

//***************--------------------------****************************
int main(){
int size;
cout<<"enter the size of an array";
cin>>size;
int arr[size];
for(int i=0;i<size;i++){
    cout<<"enter the elements";
    cin>>arr[i];
}

for(int i=0;i<size;i++){
    cout<<"arr["<<i<<"]="<<arr[i]<<endl;

//for(int i=0;i<size;i++){      //another way of representation....
   // cout<<"["<<arr[i]<<"]";

}
}










