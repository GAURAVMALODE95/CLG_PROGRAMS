#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
void ffill(int x, int y, int o_c, int n_c)
{
    int z = getpixel(x, y);
    if (z == o_c)
    {
        delay(0.3);
        putpixel(x, y, n_c);
        ffill(x + 1, y, o_c, n_c);
        ffill(x - 1, y, o_c, n_c);
        ffill(x, y + 1, o_c, n_c);
        ffill(x, y - 1, o_c, n_c);
    }
}
int main()
{
    int x1, y1, x2, y2, x3, y3, xa, ya;
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, NULL);
    cout << "enter the cordinates for tringle : " << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    setcolor(1);
    xa = (int)(x1 + x2 + x3) / 3;
    ya = (int)(y1 + y2 + y3) / 3;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    ffill(xa, ya, BLACK, GREEN);
    closegraph();

    return 0;
}