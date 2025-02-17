#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

void drawFace(int x, int y) {
    // Draw face (circle)
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(x, y, YELLOW); // Fill the face with yellow
    circle(x, y, 100); // Face outline

    // Draw eyes (two circles)
    setcolor(BLACK);
    circle(x - 40, y - 30, 10); // Left eye
    circle(x + 40, y - 30, 10); // Right eye

    // Draw pupils (two smaller circles)
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x - 40, y - 30, BLACK); // Left pupil
    floodfill(x + 40, y - 30, BLACK); // Right pupil

    // Draw mouth (arc)
    arc(x, y + 20, 0, 180, 50); // Smile
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = getmaxx() / 2; // Center of the screen
    int centerY = getmaxy() / 2;

    drawFace(centerX, centerY);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}



// g++ -I include -c ./src/smily.c -o ./build/smily.o
// g++  ./build/smily.o  -o ./build/smily.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

