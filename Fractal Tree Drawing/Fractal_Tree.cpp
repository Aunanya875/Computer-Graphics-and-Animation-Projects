#include <graphics.h>
#include <cmath>

const int width = 600;
const int height = 420;

void drawTree(int x, int y, int length, double angle, int depth) {
    if (depth == 0) {
        return;
    }

    int endX = x + static_cast<int>(length * cos(angle));
    int endY = y + static_cast<int>(length * sin(angle));  // Invert the sign here

    line(x, y, endX, endY);

    drawTree(endX, endY, length * 0.8, angle - 0.4, depth - 1);  // Invert the angle here
    drawTree(endX, endY, length * 0.8, angle + 0.4, depth - 1);  // Invert the angle here
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 3);

    int startX = width / 2;
    int startY = height;
    int length = 100;
    double angle = -1.57;  // -90 degrees in radians
    int depth = 8;

    drawTree(startX, startY, length, angle, depth);
    line(0, startY, startX+500, startY);

    getch();
    closegraph();
    return 0;
}
