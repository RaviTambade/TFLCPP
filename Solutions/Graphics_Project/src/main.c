#include <graphics.h>
#include <conio.h> // For getch()

int main()
{
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Set color and draw a line
    setcolor(YELLOW);
    line(0, 0, 200,200);

    //cleardevice();
    //bar(100, 100, 200, 200);
    bar3d(100, 100, 200, 200, 20, 1);
    // Pause to view the result
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}

//one command for creating exe
// g++ -o output  main.c -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

//indetail commands for creating ext

//g++ -I include -c ./src/main.c -o ./build/main.o
//g++  ./build/main.o  -o ./build/output.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32
