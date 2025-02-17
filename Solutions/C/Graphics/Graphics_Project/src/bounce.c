#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

#define NUM_CIRCLES 5
#define MAX_RADIUS 30

typedef struct {
    int x, y;
    int radius;
    int xSpeed, ySpeed;
    int color;
} Circle;

void initializeCircle(Circle *c) {
    c->radius = rand() % MAX_RADIUS + 10;
    c->x = rand() % (getmaxx() - c->radius * 2) + c->radius;
    c->y = rand() % (getmaxy() - c->radius * 2) + c->radius;
    c->xSpeed = (rand() % 5) + 1;
    c->ySpeed = (rand() % 5) + 1;
    c->color = rand() % 15 + 1; // Random color
}

void drawAnimatedCircles() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Circle circles[NUM_CIRCLES];

    for (int i = 0; i < NUM_CIRCLES; i++) {
        initializeCircle(&circles[i]);
    }

    while (!kbhit()) {
        cleardevice();

        for (int i = 0; i < NUM_CIRCLES; i++) {
            setcolor(circles[i].color);
            circle(circles[i].x, circles[i].y, circles[i].radius);

            circles[i].x += circles[i].xSpeed;
            circles[i].y += circles[i].ySpeed;

            if (circles[i].x + circles[i].radius >= getmaxx() || circles[i].x - circles[i].radius <= 0) {
                circles[i].xSpeed = -circles[i].xSpeed;
                circles[i].color = rand() % 15 + 1; // Change color
            }
            if (circles[i].y + circles[i].radius >= getmaxy() || circles[i].y - circles[i].radius <= 0) {
                circles[i].ySpeed = -circles[i].ySpeed;
                circles[i].color = rand() % 15 + 1; // Change color
            }
        }

        delay(30);
    }

    closegraph();
}

int main() {
    drawAnimatedCircles();
    return 0;
}


//g++ -I include -c ./src/bounce.c -o ./build/bounce.o
//g++  ./build/bounce.o  -o ./build/bounce.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

