#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void drawPetal(int x, int y, int radius, int angle) {
    for (int i = 0; i < 360; i += 30) {
        float rad = i * M_PI / 180; // Convert degrees to radians
        int petalX = x + (int)(radius * cos(rad + angle * M_PI / 180));
        int petalY = y + (int)(radius * sin(rad + angle * M_PI / 180));
        circle(petalX, petalY, radius / 3);
    }
}

void drawFlower(int x, int y) {
    // Draw petals
    setcolor(YELLOW);
    for (int i = 0; i < 360; i += 45) {
        drawPetal(x, y, 150, i);
    }

    // Draw center of the flower
    setcolor(RED);
    circle(x, y, 30);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = getmaxx() / 2; // Center of the screen
    int centerY = getmaxy() / 2;

    drawFlower(centerX, centerY);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}


// g++ -I include -c ./src/flower.c -o ./build/flower.o
// g++  ./build/flower.o  -o ./build/flower.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32
