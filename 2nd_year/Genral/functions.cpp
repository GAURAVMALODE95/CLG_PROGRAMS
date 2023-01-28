#include<iostream>
using namespace std;

//simpe functon doing arithamatic operations


int add(int a,int b){
    cout<<"addition is"<<" "<<a+b;
    }

int mult(int a,int b){
    cout<<"multiplicatio is"<<" "<<a*b;
    }

int sub(int a,int b){
    cout<<"substraction is"<<" "<<a-b;
    }
int main(){
int a,b;
cin>>a>>b;
add(a,b);
cout<<endl;
sub(a,b);
cout<<endl;
mult(a,b);



//finds maximum of two numbers
int max(int a,int b){
    if(a>b){
        cout<<a<<" "<<"is greater than"<<" "<<b;
    }
    if(b>a){
        cout<<b<<" "<<"is greater than"<<" "<<a;
    }
}
int main(){
int a;
cin>>a;
int b;
cin>>b;
max(a,b);
}//max function sucessfully implemented



//leap year function
int isleapyear(int n){
    if(n%4==0){
        cout<<n<<" "<<"is a leap year";
    }
    else if(n%4!=0){
        cout<<n<<" "<<"is not a leap year";
    }
}

int main(){
    int n;
    cin>>n;
    isleapyear(n);


 return 0;
 
}