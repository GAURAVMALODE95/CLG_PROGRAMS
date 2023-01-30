#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"enter no of elements in array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }

    
    int maxno=INT_MIN;
    int minno=INT_MAX;
   for (int i=0;i<n;i++){
      maxno=max(maxno,arr[i]);
      minno=min(minno,arr[i]);
      }
      cout<<"maximum number you have entered is="<<maxno<<endl<<"minimum number you have entered is="<<minno<<" ";

}