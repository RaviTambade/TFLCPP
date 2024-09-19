#include <graphics.h>
#include <conio.h> // For getch()

int main()
{
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Set color and draw a line
    setcolor(RED);
    line(20, 20, 200,20);

    //cleardevice();
    //bar(100, 100, 200, 200);
    //bar3d(100, 100, 200, 200, 20, 1);
    // Pause to view the result


     int x=100, y=100, r=80;
    circle(x, y, r);

    rectangle(100,100,300,300);
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
