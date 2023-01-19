#include<graphics.h>
int main(){
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm,NULL);
   

    setfillstyle(SOLID_FILL,YELLOW);
    circle(140,150,80);
    floodfill(141,150,WHITE);
    getch();
    closegraph();
}