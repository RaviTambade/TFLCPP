#include <graphics.h>
#include <conio.h> // For getch()
#include <dos.h> // For delay function


void drawAnimatedCircles() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100; // Initial x position
    int y = 200; // y position
    int radius = 20;

    while (!kbhit()) { // Run until a key is pressed
        setcolor(WHITE);
        circle(x, y, radius); // Draw the circle

        delay(50); // Control speed of animation

        // Clear the circle by drawing over it with the background color
        setcolor(BLACK);
        circle(x, y, radius);

        x += 5; // Move the circle to the right

        // Reset position if it goes off screen
        if (x > getmaxx() + radius) {
            x = -radius; // Reset to start from the left
        }
    }

    closegraph(); // Close the graphics window
}



int main()
{
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Set color and draw a line
    setcolor(RED);
    line(20, 20, 200,20);
    // internal implementation of line function

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
     // drawAnimatedCircles();
    return 0;
}

//one command for creating exe
// g++ -o output  main.c -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

//indetail commands for creating ext

// g++ -I include -c ./src/main.c -o ./build/main.o
// g++  ./build/main.o  -o ./build/output.exe -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32
