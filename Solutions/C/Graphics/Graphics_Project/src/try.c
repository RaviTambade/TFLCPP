#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h> // For delay function

#define NUM_CIRCLES 10
#define MAX_RADIUS 20

typedef struct {
    int x, y;         // Position of the circle
    int radius;      // Radius of the circle
    int xSpeed, ySpeed; // Speed of the circle in x and y direction
} Circle;

void initializeCircle(Circle *c) {
    c->radius = rand() % MAX_RADIUS + 5; // Random radius
    c->x = rand() % (getmaxx() - c->radius * 2) + c->radius; // Random x
    c->y = rand() % (getmaxy() - c->radius * 2) + c->radius; // Random y
    c->xSpeed = (rand() % 5) + 1; // Random speed in x direction
    c->ySpeed = (rand() % 5) + 1; // Random speed in y direction
}

void drawAnimatedCircles() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Circle circles[NUM_CIRCLES];

    // Initialize circles
    for (int i = 0; i < NUM_CIRCLES; i++) {
        initializeCircle(&circles[i]);
    }

    while (!kbhit()) { // Run until a key is pressed
        // Clear the screen
        cleardevice();

        // Draw and update each circle
        for (int i = 0; i < NUM_CIRCLES; i++) {
            // Draw the circle
            setcolor(WHITE);
            circle(circles[i].x, circles[i].y, circles[i].radius);

            // Update position
            circles[i].x += circles[i].xSpeed;
            circles[i].y += circles[i].ySpeed;

            // Bounce off the edges
            if (circles[i].x + circles[i].radius >= getmaxx() || circles[i].x - circles[i].radius <= 0) {
                circles[i].xSpeed = -circles[i].xSpeed; // Reverse x direction
            }
            if (circles[i].y + circles[i].radius >= getmaxy() || circles[i].y - circles[i].radius <= 0) {
                circles[i].ySpeed = -circles[i].ySpeed; // Reverse y direction
            }
        }

        delay(30); // Control the speed of animation
    }

    closegraph(); // Close the graphics window
}

int main() {
    drawAnimatedCircles();
    return 0;
}


//g++ -I include -c ./src/try.c -o ./build/try.o
//g++  ./build/try.o  -o ./build/try.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

