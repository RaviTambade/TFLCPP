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