// Program to print positive number entered by the user
// If the user enters a negative number, it is skipped

using namespace std;
#include<iostream>

int main(){

    int number;
    cout<<"enter a number:-";
    cin>>number;
    if (number>0)
    {
    cout<<"you enter a number ="<<number<<endl;
    }
    else{
        cout<<"you have to enter a int plzz";
    }
    return 0;
}
// Program to check whether an integer is positive, negative or zero
using namespace std;
#include <iostream>
int main(){
    int a;
    
    cout<<"please enter a value of type int:";
    cin>>a;

    if(a==0){
        cout<<"you entered a zeroo..";
    }
    else if (a>0){
        cout<<"you entered a positive value";
    }
    else if (a<0)
    {
        cout<<"you entered a negative value";        
    }
    else{"please check what you have entered";};
    return 0;
}

//if statement example
#include <iostream>
using namespace std;
int main(){
    int i=10;
    int n;
    cout<<"enter any integer value";
    cin>>n;
    if(n==i){
        cout<<"you are correct";
    }
    if(i!=n){
        cout<<"you are wrong";
    }
    return 0;
}