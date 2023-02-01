#include<iostream>
#include<math.h>
using namespace std;
typedef struct poly
{
    int coff;
    int expo;
}p1,p2,p3;


int main(){
int x;
cout<<"enter the number of terms for polynomial p1";
cin>>x;
cout<<"enter the number of terms for polynomial p2";
cin>>y;
    for(int i=0;i<x;i++)
    {
        cout<<"enter the coff and expo value";
        cin>>p1[i].coff>>p1[i].expo;
    }
    for(int i=0;i<y;i++)
    {
        cout<<"enter the coff and expo value";
        cin>>p2[i].coff>>p2[i].expo;
    }

while(int i<x;int j<y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(p1[i].expo==p2[j].expo){
                p3[k].coff=p1[i].coff+p2[i].coff;
                p3[k].expo=p1[i].expo;
                i++;
                j++;
                k++;}


        }





    }








}
return 0;
}

