#include <graphics.h>
int main()
{
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, "");

    for(i=50; i<=getmaxx()-100; i++)
    {
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        circle(50+i, 400, 50);
        floodfill(52+i, 402, 5);
        line(5+i,450,100+i,450);
        delay(1);
        cleardevice();
    }
    for(i=getmaxx()-100; i>=0; i--)
    {
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        circle(50+i, 400, 50);
        floodfill(52+i, 402, 5);
        line(5+i,450,100+i,450);
        delay(1);
        cleardevice();
    }

    for(i=0; i<=getmaxx()-280; i++)
    {
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        circle(50+i, 400-i, 50);
        floodfill(52+i, 402-i, 5);
        line(5+i,450,100+i,450);
        delay(1);
        cleardevice();
    }
    for(i=getmaxx()-280; i>=0; i--)
    {
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        circle(50+i, 400-i, 50);
        floodfill(52+i, 402-i, 5);
        line(5+i,450,100+i,450);
        delay(1);
        cleardevice();
    }

    for(i=getmaxy()-120; i>=0; i--)
    {
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        circle(50, 50+i, 50);
        floodfill(52, 52+i, 5);
        line(450-i,450,350-i,450);
        delay(1);
        cleardevice();
    }
    for(i=0; i<=getmaxy()-120; i++)
    {
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        circle(50, 50+i, 50);
        floodfill(52, 52+i, 5);
        line(450-i,450,350-i,450);
        delay(1);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
