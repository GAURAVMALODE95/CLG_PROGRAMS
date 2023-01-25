#include<iostream>
#include<graphics.h>
using namespace std;

class lineclip{
    private:
        int RIGHT=2,LEFT=1,TOP=8,BOTTOM=4,x1,y1,x2,y2,xl,yl,xh,yh,x,y;

    public:
        int getcode(int x,int y);
        void process();
};

int lineclip::getcode(int x,int y){
    int code=0;
    if(y>xh){
        code |= TOP;
    }
    if(y<yl){
        code|=BOTTOM; 
    }
    if(x<xl){
        code|=RIGHT;
    }
    if(x>xh){
        code|=LEFT;

    }
    return code;


}

void lineclip::process(){

    int code1,code2;
    cout<<"\n\tenter the cordinates of rectringle : ";
    cin>>xl>>yl>>xh>>yh;
    setcolor(YELLOW);
    rectangle(xl,yl,xh,yh);

    cout<<"\n\tenter cordinates for line : ";
    cin>>x1>>y1>>x2>>y2;
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    delay(100000);

    code1=getcode(x1,y1);
    code2=getcode(x2,y2);
    int temp;
    float m;
    int flag=0;
    while(1){
        m=(float)(y2-y1)/(x2-x1);

        if(code1==0 && code2==0){
            flag=1;
            break;
        }
        else if((code1 & code2)!=0){
            break;
        }

        else{
            if(code1==0){
                temp=code2;
            }
            else{
                temp=code1;
            }

            if(temp & TOP){
                x=x1+(yh-y1)/m;
                y=yh;
            }
            else if(temp & BOTTOM) {
			x = x1 + (yl-y1)/m;
			y = yl;	
		    }
		    else if(temp & LEFT){
			y = y1 + m*(xl-x1);
			x = xl; 	
		    }
		    else if(temp & RIGHT){
			y = y1 + m*(xh-x1);
			x = xh; 	
		    }

            if(temp==code1){
                x1=x;
                y1=y;
                code1=getcode(x1,y2);

            }
            if(temp==code2){
                x2=x;
                y2=y;
                code2=getcode(x2,y2);
            }

        }
    }
    cleardevice();
    rectangle(xl,yl,xh,yh);
    setcolor(YELLOW);

    if(flag==1){
        line(x1,y1,x2,y2);

    }
closegraph();
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    lineclip l1;
    l1.process();
    return 0;
}