#include <graphics.h>
#include <conio.h>
#include<dos.h>

using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(DARKGRAY);
    circle(300, 220, 150);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(301, 221, DARKGRAY);

    setcolor(BLACK);
    circle(240, 158, 30);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(241, 159, BLACK);

    ellipse(250, 158, 0, 360, 6, 10);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(251, 159, BLACK);

    circle(360, 158, 30);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(361, 159, BLACK);

    ellipse(350, 158, 0, 360, 6, 10);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(351, 159, BLACK);

    pieslice(300, 180, 240, 300, 20);

    setcolor(BLACK);
    ellipse(300, 300, 0, 360, 60, 10);
    setfillstyle(SOLID_FILL, RED);
    floodfill(301, 301, BLACK);

    setcolor(RED);
    outtextxy(260, 380, "A Weird Face");

    getch();
    closegraph();
}
