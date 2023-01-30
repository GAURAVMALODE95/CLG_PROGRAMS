#include<iostream>
#include<map>
using namespace std;

int main(){
    string ch;
    typedef map<string,int> maptype;
    maptype p_map;
    p_map.insert(pair<string,int>("maharastra",214124));
    maptype::iterator it;
    cin>>ch;
    it=p_map.find(ch);
    if(it==p_map.end()){
        cout<<"no";

    }
    else{
        cout<<"yes";
    }
return 0;
}