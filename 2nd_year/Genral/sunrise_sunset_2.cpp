#include<iostream>
#include<graphics.h>
using namespace std;
int main(){
    initwindow(800,500);
    int x0,y0;
    int gdriver=DETECT,gmode;
    int xmax,ymax,i,j;
    setbkcolor(BLUE);
    setcolor(RED);
    rectangle(0,0,getmaxx(),getmaxy());

    
    for(i=50,j=0,i<=250;i=i+5;j=j+5){

        delay(100);
        cleardevice();
        if(i<=150){
            setcolor(YELLOW);
            setfillstyle(1,YELLOW);
            fillellipse(i,300-j,20,20);

        }
        else{
            setcolor(YELLOW);
            setfillstyle(1,RED);
            fillellipse(i,300-j,20,20);
        }
    }
    delay(1000);
    cleardevice();
    setcolor(RED);
    setfillstyle(1,RED);
    fillellipse(300,50,20,20);
    delay(150);

    int k,l;
    for(k=305,l=55;k<=550,l<=300;k+=5,l+=5)
    {
        delay(120);
        cleardevice();
        if(k<=450)
        {

            setcolor(GREEN^RED);
            setfillstyle(1,GREEN^RED);

            fillellipse(k,l,20,20);
        }
        else
        {
            setcolor(YELLOW);
            setfillstyle(1,YELLOW);
            fillellipse(k,l,20,20);
        }
    }
return 0;
}