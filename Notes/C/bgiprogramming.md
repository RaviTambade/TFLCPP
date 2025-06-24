## A Journey into BGI with C Language

🧓 *"Gather around, students. Let me take you back to a time before smartphones, before Windows had glossy buttons and touch screens. I’m talking about the early 90s. Computers booted into a black screen with a blinking cursor. And if you wanted to do graphics, you didn’t have a browser or Unity or even OpenGL. You had to earn your pixels... with Borland Graphics Interface—BGI."*


### 🌄 **The Motivation: Bringing Pixels to Life**

I still remember the thrill the first time I saw a circle drawn on a black screen by my own program. It was magical.

*"Back then, we used Turbo C or Turbo C++ under MS-DOS. GUI programming wasn’t for the faint-hearted. So, Borland introduced something revolutionary—a simple graphics library that allowed C programmers to create shapes, colors, and animations easily. That was BGI."*


### 🛠️ **Setting Up: The First Battle**

*"I remember fighting with include files, setting the correct paths in Turbo C IDE, and loading the right graphics driver (`EGAVGA.BGI`). If you missed that step—poof! No graphics."*

**Step-by-step:**

1. **Include the header**

   ```c
   #include <graphics.h>
   #include <conio.h>
   ```
2. **Initialize graphics mode**

   ```c
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
   ```

> "The path `C:\\TURBOC3\\BGI` was sacred. Misspell it, and the screen stayed black."

3. **Draw Something**

   ```c
   circle(200, 200, 100);
   getch();
   closegraph();
   ```

🎯 **Output**: A perfect white circle on a black screen—your first triumph in graphics!


### 🔍 **Key BGI Functions: Your Graphic Toolbox**

Let me walk you through some that shaped our projects:

| Function       | Purpose                    |
| -------------- | -------------------------- |
| `initgraph()`  | Initializes graphics mode  |
| `circle()`     | Draws a circle             |
| `line()`       | Draws a line               |
| `rectangle()`  | Draws a rectangle          |
| `bar()`        | Draws filled rectangle     |
| `setcolor()`   | Sets current drawing color |
| `setbkcolor()` | Sets background color      |
| `outtextxy()`  | Displays text at (x, y)    |
| `putpixel()`   | Plots a single pixel       |
| `getpixel()`   | Reads the color of a pixel |


### 🎮 **Mini Project: Smiley Face in C using BGI**

*"I once gave this as a lab assignment—to draw a smiley face. The challenge wasn’t the drawing—it was mastering coordinates, angles, and timing."*

```c
#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(YELLOW);
    circle(250, 200, 100); // Face

    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(250, 200, YELLOW);

    setcolor(BLACK);
    circle(220, 170, 10); // Left eye
    circle(280, 170, 10); // Right eye

    arc(250, 200, 200, 340, 40); // Smile

    getch();
    closegraph();
    return 0;
}
```


### 🧠 **Lessons I Learned from BGI (Beyond the Code)**

1. **Graphics is math + creativity**: BGI made me love geometry.
2. **Debugging without Google**: I learned patience.
3. **Coordinate system mastery**: It set the stage for later learning in OpenGL and game dev.
4. **Appreciation for abstraction**: BGI was a high-level wrapper over VGA functions—an early lesson in APIs.


### 🕰️ **BGI's Legacy**

*"Today, you have PyGame, Unity, WebGL. But the principles are the same—coordinate systems, shapes, color theory. BGI was my first brush with graphics. Primitive, yes. But it taught me how machines see space, how pixels work, and how logic becomes art."*


### 🔚 Final Words

👨‍🏫 *"If you ever get the chance, try writing a BGI program—even today in DOSBox or Turbo C emulator. It’s humbling and beautiful. You’ll see how far we’ve come—and how much of what we do today rests on those black screens with white pixels."*

Let me know, I’m happy to continue this mentor journey with you!

# BGI (Borland Graphics Interface) with C language

To use BGI (Borland Graphics Interface) with C language on Windows using MinGW, you need to follow a series of steps to set up your environment and get started with graphics programming. Here's a concise guide to help you out:

### Step 1: Install MinGW

1. **Download MinGW**:
   - Go to the [MinGW official website](http://www.mingw.org/) and download the installer.

2. **Install MinGW**:
   - During installation, select the `mingw32-base` and `mingw32-gcc-g++` packages to install.

3. **Add MinGW to Path**:
   - Add the `C:\MinGW\bin` directory to your system's PATH environment variable.

### Step 2: Download BGI Graphics Library

1. **Download BGI Files**:
   - You can download the BGI graphics library files (e.g., `graphics.h`, `winbgim.h`, `libbgi.a`, etc.) from repositories like [WinBGIm](http://winbgim.codecutter.org/).

2. **Set Up BGI Files**:
   - Place the downloaded BGI files in the appropriate directories:
     - `graphics.h`, `winbgim.h`, and other header files in `C:\MinGW\include`.
     - The library file `libbgi.a` in `C:\MinGW\lib`.
     - The BGI fonts directory (e.g., `C:\MinGW\lib\libbgi.a`) should contain the BGI fonts.

### Step 3: Write a Sample BGI Program

Here’s a simple example to test if everything is set up correctly:

```c
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    // Initialize graphics
    initgraph(&gd, &gm, "");

    // Draw a simple line
    line(100, 100, 200, 200);
    circle(300, 200, 50);

    // Wait for user input
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}
```

### Step 4: Compile the Program

To compile your program using MinGW, follow these steps:

1. Open Command Prompt.
2. Navigate to the directory where your C file is saved.
3. Compile the program with the following command:

```bash
gcc -o mygraphics mygraphics.c -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```

### Step 5: Run Your Program

After successful compilation, run your program by typing:

```bash
mygraphics
```

### Additional Tips

- Make sure to check for any errors during compilation. If there are missing files, double-check your BGI setup.
- You can explore more functions in the graphics library for different shapes and text.
- Look into the WinBGIm documentation for additional functionalities and examples.

With these steps, you should be able to start programming graphics using BGI in C with MinGW. Happy coding!



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

 
 # Graphics functions in the BGI (Borland Graphics Interface) library
### BGI Reusable Graphics Functions

1. **Initialization Functions**
   - `initgraph(&gd, &gm, "");`  
     Initializes the graphics system.

2. **Clearing the Screen**
   - `cleardevice();`  
     Clears the current graphics screen.

3. **Drawing Functions**
   - `line(int x1, int y1, int x2, int y2);`  
     Draws a line between two points.
   - `rectangle(int left, int top, int right, int bottom);`  
     Draws a rectangle defined by two corners.
   - `circle(int x, int y, int radius);`  
     Draws a circle with a specified center and radius.
   - `ellipse(int x, int y, int startAngle, int endAngle, int xRadius, int yRadius);`  
     Draws an ellipse or arc.
   - `bar(int left, int top, int right, int bottom);`  
     Draws a filled rectangle (bar).
   - `floodfill(int x, int y, int borderColor);`  
     Fills a bounded area with the current fill color.

4. **Polygon Functions**
   - `drawpoly(int numberOfPoints, int *points);`  
     Draws a polygon based on an array of points.
   - `fillpoly(int numberOfPoints, int *points);`  
     Fills a polygon with the current fill style.

5. **Color and Fill Functions**
   - `setcolor(int color);`  
     Sets the current drawing color.
   - `setfillstyle(int pattern, int color);`  
     Sets the fill pattern and color.
   - `setbkcolor(int color);`  
     Sets the background color.
   - `getcolor();`  
     Returns the current drawing color.

6. **Text Functions**
   - `outtextxy(int x, int y, const char *text);`  
     Displays a string of text at a specified position.
   - `settextstyle(int font, int direction, int size);`  
     Sets the font style and size for text.

7. **Pixel Functions**
   - `putpixel(int x, int y, int color);`  
     Sets the color of a pixel at (x, y).
   - `getpixel(int x, int y);`  
     Retrieves the color of a pixel at (x, y).

8. **Arc and Sector Functions**
   - `arc(int x, int y, int startAngle, int endAngle, int radius);`  
     Draws an arc.
   - `drawsector(int x, int y, int startAngle, int endAngle, int radius);`  
     Draws a filled sector.

9. **Coordinate System Functions**
   - `getmaxx();`  
     Returns the maximum x-coordinate of the current graphics mode.
   - `getmaxy();`  
     Returns the maximum y-coordinate of the current graphics mode.

10. **Closing Functions**
    - `closegraph();`  
      Closes the graphics system and deallocates memory.

### Example of a Reusable Function

You can create a reusable function to draw a filled circle:

```c
void drawFilledCircle(int x, int y, int radius, int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    floodfill(x, y, color); // Fill color
    circle(x, y, radius);   // Draw circle outline
}
```

### Conclusion

These functions provide a robust toolkit for creating graphics applications in C using the BGI library. You can easily combine these functions to create more complex shapes and designs. If you have any specific needs or further questions, feel free to ask!