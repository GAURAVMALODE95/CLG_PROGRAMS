#include<iostream>
#include<fstream>
using namespace std;

int main(){
/* 
   ofstream gaurav("sample.txt");
    string name;
    cout<<"enter name";
    cin>>name;//created string and connect with my name is  ):
    
    gaurav<<"my name is : "<<name;
    gaurav.close();//file closed.//link broked):


*/
    ifstream hii("sample.txt");
    string content;
    getline(hii,content);
    cout<<content;
    hii.close();
    
return 0;
}