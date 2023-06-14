#include<stdio.h>
#include<graphics.h>

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");

    //main body
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,DARKGRAY);
    rectangle(200,100,300,300);
    floodfill(210,110,WHITE);

    //pool
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    rectangle(240,300,260,500);
    floodfill(250,310,WHITE);

    for (int i=0;i=10;i++)
    {
        //redlight
        setfillstyle(SOLID_FILL,RED);
        circle(250,135,25);
        floodfill(255,140,WHITE);
        delay(2000);

        //yellow light
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(255,140,WHITE);
        setfillstyle(SOLID_FILL,YELLOW);
        circle(250,200,25);
        floodfill(255,210,WHITE);
        delay(2000);

        //green light
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(255,210,WHITE);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,GREEN);
        circle(250,265,25);
        floodfill(255,270,WHITE);
        delay(2000);

        setfillstyle(SOLID_FILL,BLACK);
        floodfill(255,270,WHITE);

    }
    getch();
    closegraph();
}

