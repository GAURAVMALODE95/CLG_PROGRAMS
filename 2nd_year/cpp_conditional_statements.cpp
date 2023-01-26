using namespace std;
#include <iostream>
int main(){
    //simple if else program in cpp
    int n;
    cout<<"enter any integer value and i will tell you that value is negative or positive";
    cin>>n;
    if(n>0){
        cout<<"n is a positive integer";
    }
    else if(n<0)
    {cout<<"n is a negative integer";}
    
   //simple program which will take input from user of two numbers and tell him which is greater
   int a;
   int b;
   cout<<"enter value of first integer"; 
   cin>>a;
   cout<<"enter value of second integer"; 
   cin>>b;
   cout<<"a="<<a<<endl;
   cout<<"b="<<b<<endl;
   if(a>b){
    cout<<"the value you entered firts that is"<<" "<<a<<" "<<"is greater than" <<" "<<b<<endl;
   }
   else{cout<<"the value you entered second that is"<<"  "<<b<<" "<<"is greater than"<<" "<<a<<endl;}
   cout<<"thamk you sir have a nice day";
    return 0;
}