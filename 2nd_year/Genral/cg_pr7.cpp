#include <iostream>
#include <graphics.h>
#include <cstdlib>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int x, y, i, flag = 0;
    initgraph(&gd, &gm, NULL);

    x = getmaxx() / 2;
    y = getmaxy() / 2;

    while (1)
    {

        if (y >= getmaxy() - 30 || y <= 30)
        {
            flag = !flag;
        }

        setcolor(RED);
        circle(x, y, 30);
        floodfill(x, y, YELLOW);
        delay(100);
        cleardevice();
        if (flag)
        {
            y = y + 5;
        }
        else
        {
            y = y - 5;
        }
    }
    delay(5000);
    closegraph();
    return 0;

    return 0;
}