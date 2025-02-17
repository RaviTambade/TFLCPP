#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main()
{   
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(WHITE);
    while (true) 
    {
        cleardevice();
        // Set text style
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        char buffer[100];
         int x = mousex();
        int y = mousey();
        sprintf(buffer, "X=%d, Y=%d", x,y);
        // Display text at specified coordinates
        outtextxy(10, 10, buffer);
        outtextxy(x, y, "*");
        delay(100);
    }

    // Wait for a key press to exit
    getch();
    closegraph();
    return 0;
}



/*

Buffer: Ensure the buffer is large enough to hold the formatted string.
Format Specifiers: Use %d for integers, %f for floats, and %s for strings, among others.
Return Value: sprintf returns the number of characters written, excluding the null terminator.



*/
//one command for creating exe
// g++ -o output  mouse.c -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32
