# Graphics Shapes Drawing using BGI

Let us explore simple BGI graphics programs.
### 1. Drawing Shapes

This program demonstrates how to draw basic shapes like lines, circles, and rectangles.

```c
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a line
    line(100, 100, 200, 200);

    // Draw a rectangle
    rectangle(50, 50, 150, 150);

    // Draw a circle
    circle(300, 200, 50);

    // Draw an ellipse
    ellipse(400, 200, 0, 360, 100, 50);

    getch(); // Wait for a key press
    closegraph();
    return 0;
}
```

### 2. Filling Shapes

This program shows how to fill shapes with colors.

```c
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set fill style and color
    setfillstyle(SOLID_FILL, RED);
    floodfill(100, 100, WHITE); // Fill background
    rectangle(50, 50, 150, 150);
    floodfill(100, 100, WHITE); // Fill rectangle

    setfillstyle(SOLID_FILL, BLUE);
    floodfill(300, 200, WHITE); // Fill background
    circle(300, 200, 50);
    floodfill(300, 200, WHITE); // Fill circle

    getch();
    closegraph();
    return 0;
}
```

### 3. Drawing a Simple House

This program creates a simple house shape using lines and rectangles.

```c
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw house base
    rectangle(150, 200, 350, 400);
    
    // Draw roof
    line(150, 200, 250, 100); // Left roof
    line(250, 100, 350, 200); // Right roof

    // Draw door
    rectangle(230, 300, 270, 400);
    
    // Draw windows
    rectangle(170, 250, 220, 300); // Left window
    rectangle(280, 250, 330, 300); // Right window

    getch();
    closegraph();
    return 0;
}
```

### 4. Moving a Circle

This program demonstrates simple animation by moving a circle across the screen.

```c
#include <graphics.h>
#include <conio.h>
#include <dos.h> // For delay function

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 50, y = 200; // Starting position

    for (int i = 0; i < 300; i++) {
        // Clear the previous circle
        cleardevice();

        // Draw the circle
        circle(x, y, 20);
        
        // Update position
        x += 1; 
        delay(10); // Delay for smooth animation
    }

    getch();
    closegraph();
    return 0;
}
```

### 5. Simple Text Display

This program shows how to display text on the screen.

```c
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the text style
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(200, 200, "Hello, BGI Graphics!");

    getch();
    closegraph();
    return 0;
}
```

### Running the Programs

1. Save each example as a `.c` file.
2. Compile using the command:

```bash
gcc -o myprogram myprogram.c -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```

3. Run the compiled program:

```bash
myprogram
```

 