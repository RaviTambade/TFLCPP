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