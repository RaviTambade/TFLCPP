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
    line(20, 40, 200,40);
    line(20, 60, 200,60);
    line(20, 80, 200,80);
    line(20, 100, 200,100);

    line(20, 20, 20,100);
    line(40, 20, 20,100);
    line(60, 20, 20,100);
    line(80, 20, 20,100);

 
     getch();

    // Close the graphics mode
    closegraph();
    
    return 0;
}

//one command for creating exe
// g++ -o output  main.c -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

//indetail commands for creating ext

// g++ -I include -c ./src/box.c -o ./build/box.o
// g++  ./build/box.o  -o ./build/output.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32
