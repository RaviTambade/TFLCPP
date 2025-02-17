#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void drawTriangle(int x, int y, int size) {
    int halfBase = size / 2;
    int height = (int)(sqrt(3) / 2 * size);
    
    int points[] = {
        x, y - height,    // Top vertex
        x - halfBase, y + height / 2, // Bottom left vertex
        x + halfBase, y + height / 2, // Bottom right vertex
        x, y - height      // Close the triangle
    };

    setcolor(WHITE);
    drawpoly(4, points); // Draw the triangle outline
    setfillstyle(SOLID_FILL, YELLOW);
    fillpoly(4, points); // Fill the triangle with blue
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawTriangle(getmaxx() / 2, getmaxy() / 2, 100);

    getch();
    closegraph();
    return 0;
}


// g++ -I include -c ./src/triangle.c -o ./build/triangle.o
// g++  ./build/triangle.o  -o ./build/triangle.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32


