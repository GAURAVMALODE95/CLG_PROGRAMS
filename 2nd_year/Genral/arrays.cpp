//you can put same type of elements in array.ex.int,char,etc.
//no diffrent type of elements are allowed.
/* continous memory location.
   we can acces elements using indexing.*/

//lets do some coding####
#include<iostream>
#include<climits>
using namespace std;
int main(){
   int tuskon[13];
   //cout<<"relax everything is fine no error is genrated and your array is created\n";
   //cout<<"\n value at index 0 is="<<tuskon[0]<<endl;
   //cout<<"\n value at index 1 is="<<tuskon[1]<<endl;//output is 4201024 that means garbage value is there.
   //cout<<"\n value at index 2 is="<<tuskon[2]<<endl;//again garbage value is genrated
   //lets try a location ehich is not in array.
   //cout<<"\n value at index 16 is="<<tuskon[200]<<endl;//nothing is displaye
   



   //int sheild[3]={1,2323,352525};
   /*cout<<"in array sheild element at index 2 is="<<sheild[2]<<endl;
   
   int third[15]={1,5,6,3,46,45,34,574,534,346};
   int n=15;
   for (int i=0;i<n;i++){

      cout<<third[i]<<" ";//displays 0 for elements which are not declared

   }*/



/* lets make array of other data type.
   char ch[12]={'a','b','c','d','e','f'};
  //cout<<ch[5]<<endl;//print element at 5
   for (int i=0;i<5;i++){
      cout<<ch[i]<<" ";

   }*/

 /*  float namibia[10];
   for (int i=0; i<11;i++){

      cout<<namibia[i]<<" ";
   } */



   int n;
   cout<<"enter for number of elements";
   cin>>n;
   int arr[n];
   for( int i=0 ; i<n ; i++ ){
      cin>>arr[i];
   

   cout<<arr[i]<<" "<<endl;
   }
   //for maximum number
   int maxno=INT_MIN;
   int minno=INT_MAX;
   for (int i=0;i<n;i++){
      maxno=max(maxno,arr[i]);
      minno=min(minno,arr[i]);
      }
      cout<<"maximum number you have entered is="<<maxno<<endl<<"minimum number you have entered is="<<minno<<" ";
//this is the logic for maximum and minimum numbers in a array
   

   

   





   return 0;
   



}

   