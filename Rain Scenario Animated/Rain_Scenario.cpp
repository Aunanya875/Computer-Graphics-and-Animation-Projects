#include <graphics.h>
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight * 0.95
int ldisp=0;
using namespace std;

int main()
{
    int ldisp = 0;
    int gd = DETECT, gm;
    int x=0;
    initgraph(&gd, &gm, "");

    while(!kbhit())
    {
        //cloud 1
        circle(50, 90, 20);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(51,91,WHITE);

        circle(108, 80, 20);
        floodfill(109,81,WHITE);

        circle(73, 80, 20);
        floodfill(74,81,WHITE);

        circle(130, 90, 10);
        floodfill(131,91,WHITE);

        circle(108, 90, 20);
        floodfill(109,101,WHITE);

        circle(73, 100, 22);
        floodfill(74,101,WHITE);

        //cloud 2
        circle(350, 90, 20);
        floodfill(351,91,WHITE);

        circle(408, 80, 20);
        floodfill(409,81,WHITE);

        circle(373, 80, 20);
        floodfill(374,81,WHITE);

        circle(430, 90, 10);
        floodfill(431,91,WHITE);

        circle(408, 90, 20);
        floodfill(409,101,WHITE);

        circle(373, 100, 22);
        floodfill(374,101,WHITE);

        //house
        int tri[]={100,150, 50, 200, 150, 200, 100, 150};
        drawpoly(4, tri);
        setfillstyle(INTERLEAVE_FILL, LIGHTGRAY);
        fillpoly(4, tri);

        int trec[]={50, 200, 150, 200, 150, 300, 50, 300, 50, 200};
        drawpoly(5, trec);
        setfillstyle(SOLID_FILL, RED);
        fillpoly(5, trec);

        int tw[]={80, 210, 120, 210, 120, 240, 80, 240, 80, 210};
        drawpoly(5, tw);
        setfillstyle(LINE_FILL, DARKGRAY);
        fillpoly(5, tw);

        int td[]={75, 250, 125, 250, 125, 300, 75, 300, 75, 250};
        drawpoly(5, td);
        setfillstyle(SOLID_FILL, DARKGRAY);
        fillpoly(5, td);
        circle(120, 275, 5);

        int rom[]={100, 150, 230, 150, 280, 200, 150, 200, 100, 150};
        drawpoly(5, rom);
        setfillstyle(INTERLEAVE_FILL, LIGHTGRAY);
        fillpoly(5, rom);

        int rrec[]={150, 200, 280, 200, 280, 300, 150, 300, 150, 200};
        drawpoly(5, rrec);
        setfillstyle(SOLID_FILL, RED);
        fillpoly(5, rrec);

        int rw1[]={160, 210, 200, 210, 200, 240, 160, 240, 160, 210};
        drawpoly(5, rw1);
        setfillstyle(LINE_FILL, DARKGRAY);
        fillpoly(5, rw1);

        int rw2[]={230, 210, 270, 210, 270, 240, 230, 240, 230, 210};
        drawpoly(5, rw2);
        setfillstyle(LINE_FILL, DARKGRAY);
        fillpoly(5, rw2);

        int rd[]={190, 250, 240, 250, 240,300, 190, 300, 190, 250};
        drawpoly(5, rd);
        setfillstyle(SOLID_FILL, DARKGRAY);
        fillpoly(5, rd);
        circle(235, 275, 5);

        setcolor(YELLOW);
        circle(250 , 50, 20);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(251, 51, YELLOW);

        //human
        setcolor(WHITE);
        circle(x, GroundY - 90, 10);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x, GroundY - 90, WHITE);

        line(x,GroundY-80,x,GroundY-40);
        line(x,GroundY-70,x+10,GroundY-60);
        line(x,GroundY-65,x+10,GroundY-55);
        line(x+10,GroundY-60,x+20,GroundY-70);
        line(x+10,GroundY-55,x+20,GroundY-70);
        line(x+20,GroundY-70,x+20,GroundY-120);

        line(x,GroundY-40,x+ldisp,GroundY-8);
        line(x,GroundY-40,x-ldisp,GroundY-8);

        setfillstyle(SOLID_FILL, BLUE);
        setcolor(WHITE);
        pieslice(x+20,GroundY-120,0,180,50);

        setcolor(WHITE);
        int i, rx, ry;
        for (i = 0; i <= 700; i++)
        {
            rx = rand() % ScreenWidth;
            ry = rand() % ScreenHeight;
            if (ry < GroundY - 4)
            {
                if (ry < GroundY-120 || (ry > GroundY-120 && (rx < x-25 || rx > x+65)))
                line(rx, ry, rx + 0.5, ry + 4);
            }
        }

        delay(20);
        cleardevice();
        x = (x + 2) % ScreenWidth;
        ldisp=(ldisp+2)%20;
        //line(0, GroundY, ScreenWidth, GroundY);
        //line(0, GroundY-170, ScreenWidth, GroundY-170);
        int field[]={0, GroundY-170, ScreenWidth, GroundY-170, ScreenWidth, GroundY, 0, GroundY, 0, GroundY-170};
        drawpoly(5, field);
        setfillstyle(SOLID_FILL, GREEN);
        fillpoly(5, field);

        int road[]={0, GroundY-50, ScreenWidth, GroundY-50, ScreenWidth, GroundY, 0, GroundY, 0, GroundY-50};
        drawpoly(5, road);
        setfillstyle(SOLID_FILL, DARKGRAY);
        fillpoly(5, road);

    }
    getch();
    closegraph();
}

