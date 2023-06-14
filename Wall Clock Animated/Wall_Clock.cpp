#include <graphics.h>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <sstream>

const int width = 800;
const int height = 600;
const int clockRadius = 200;
const int hourHandLength = 80;
const int minuteHandLength = 120;
const int secondHandLength = 140;
const int digitalTimeSize = 3;

void drawClock(int hour, int minute, int second) {
    // Clear screen
    cleardevice();

    // Draw clock face
    setcolor(WHITE);
    circle(width / 2, height / 2, clockRadius);

    // Draw hour stripes
    setcolor(WHITE);
    for (int i = 0; i < 12; ++i) {
        int x1 = width / 2 + static_cast<int>(clockRadius * cos((i * 30 - 90) * M_PI / 180));
        int y1 = height / 2 + static_cast<int>(clockRadius * sin((i * 30 - 90) * M_PI / 180));
        int x2 = width / 2 + static_cast<int>((clockRadius - 20) * cos((i * 30 - 90) * M_PI / 180));
        int y2 = height / 2 + static_cast<int>((clockRadius - 20) * sin((i * 30 - 90) * M_PI / 180));
        line(x1, y1, x2, y2);

        char digit[2];
        sprintf(digit, "%d", i);
        int digitX = width / 2 + static_cast<int>((clockRadius - 40) * cos((i * 30 - 90) * M_PI / 180)) - textwidth(digit) / 2;
        int digitY = height / 2 + static_cast<int>((clockRadius - 40) * sin((i * 30 - 90) * M_PI / 180)) - textheight(digit) / 2;
        outtextxy(digitX, digitY, digit);
    }

    // Draw hour hand
    setcolor(WHITE);
    int hourAngle = (hour % 12) * 30 - 90;
    int hourX = width / 2 + static_cast<int>(hourHandLength * cos(hourAngle * M_PI / 180));
    int hourY = height / 2 + static_cast<int>(hourHandLength * sin(hourAngle * M_PI / 180));
    line(width / 2, height / 2, hourX, hourY);

    // Draw minute hand
    setcolor(WHITE);
    int minuteAngle = minute * 6 - 90;
    int minuteX = width / 2 + static_cast<int>(minuteHandLength * cos(minuteAngle * M_PI / 180));
    int minuteY = height / 2 + static_cast<int>(minuteHandLength * sin(minuteAngle * M_PI / 180));
    line(width / 2, height / 2, minuteX, minuteY);

    // Draw second hand
    setcolor(WHITE);
    int secondAngle = second * 6 - 90;
    int secondX = width / 2 + static_cast<int>(secondHandLength * cos(secondAngle * M_PI / 180));
    int secondY = height / 2 + static_cast<int>(secondHandLength * sin(secondAngle * M_PI / 180));
    line(width / 2, height / 2, secondX, secondY);

    // Draw digital time display
    settextstyle(DEFAULT_FONT, HORIZ_DIR, digitalTimeSize);
    setcolor(BLACK);
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second;
    outtextxy(width / 2 - 3 * digitalTimeSize, height / 2 + clockRadius + digitalTimeSize, const_cast<char*>(oss.str().c_str()));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (!kbhit()) {
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);

        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;

        drawClock(hour, minute, second);

        delay(1000);
    }

    closegraph();
    return 0;
}
