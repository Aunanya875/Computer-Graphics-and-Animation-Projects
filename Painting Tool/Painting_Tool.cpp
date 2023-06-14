#include <graphics.h>
#include <iostream>

const int width = 800;
const int height = 600;

void drawLine(int startX, int startY, int endX, int endY, int color) {
    setcolor(color);
    line(startX, startY, endX, endY);
}

void drawRectangle(int startX, int startY, int endX, int endY, int color) {
    setcolor(color);
    rectangle(startX, startY, endX, endY);
}

void drawCircle(int centerX, int centerY, int radius, int color) {
    setcolor(color);
    circle(centerX, centerY, radius);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int startX, startY, endX, endY;
    int shape = -1;
    int color = WHITE;

    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, startX, startY);
        } else if (ismouseclick(WM_LBUTTONUP)) {
            getmouseclick(WM_LBUTTONUP, endX, endY);

            switch (shape) {
                case 0:
                    drawLine(startX, startY, endX, endY, color);
                    break;
                case 1:
                    drawRectangle(startX, startY, endX, endY, color);
                    break;
                case 2:
                    {
                        int radius = abs(startX - endX);
                        int centerX = (startX + endX) / 2;
                        int centerY = (startY + endY) / 2;
                        drawCircle(centerX, centerY, radius, color);
                    }
                    break;
                default:
                    break;
            }

            shape = -1;
        }

        if (ismouseclick(WM_RBUTTONDOWN)) {
            cleardevice();
        }

        if (kbhit()) {
            int key = getch();
            if (key == '1') {
                shape = 0;  // Line
            } else if (key == '2') {
                shape = 1;  // Rectangle
            } else if (key == '3') {
                shape = 2;  // Circle
            } else if (key == 'c') {
                setcolor(BLACK);
                color = BLACK;
            } else if (key == 'r') {
                setcolor(RED);
                color = RED;
            } else if (key == 'g') {
                setcolor(GREEN);
                color = GREEN;
            } else if (key == 'b') {
                setcolor(BLUE);
                color = BLUE;
            }
        }

        delay(10);
    }

    closegraph();
    return 0;
}

