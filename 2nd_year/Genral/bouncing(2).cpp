#include <iostream>
#include <cstdlib>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT;
    int gm, x, y,flag=0;
    initgraph(&gd,&gm,NULL);
    x = getmaxx() / 2;
    y = getmaxy() / 2;
    while (1)
    {
        if (y > getmaxy() - 30||y<=30)
        {
            flag = !flag;
        }
        setcolor(RED);
        circle(x, y, 30);
        floodfill(x, y, RED);
        delay(1);
        cleardevice();

        if (flag)
        {
            y += 5;
        }
        else
        {
            y -= 5;
        }
    }
    delay(20);
    closegraph();
    return 0;
}