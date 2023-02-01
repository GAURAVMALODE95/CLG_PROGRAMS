#include <graphics.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	circle(250, 200, 50);
	getch();
	closegraph();
	return 0;
}