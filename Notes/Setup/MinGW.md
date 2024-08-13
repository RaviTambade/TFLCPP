When using MinGW (Minimalist GNU for Windows) for C++ development, you might need to manage projects that span multiple C++ files. Here's a guide on how to organize and compile a C++ project with multiple source files using MinGW:

### 1. **Organize Your Files**

**Project Structure:**

```
Basic_Project/
├── src/
│   ├── main.cpp
│   ├── handler.cpp
│   └── math.cpp
├── include/
│   ├── math.h
│   └── handler.h
└── build/
```

- **`include/`**: Directory for header files.
- **`src/`**: Directory for source files.
- **`build/`**: Directory for output binaries and intermediate files (optional but recommended).

### 2. **Create Header Files**

Header files declare the interfaces of your classes or functions.

**`include/handler.h`**
```cpp
#ifndef HANDLER_H
#define HANDLER_H

void displayMessage();
 
#endif // MYCLASS_H
```

**`include/math.h`**
```cpp
#ifndef MATH_H
#define MATH_H

int addition(int num1, int num2);
int subtraction(int num1, int num2);
int division(int num1, int num2);
int multiplication(int num1, int num2);

#endif // ANOTHERCLASS_H
```

### 3. **Create Source Files**

Source files define the implementations of your classes or functions.

**`src/handler.cpp`**
```cpp
#include "handler.h"
#include <iostream>
using namespace std;   //import namespace

//Actual Function implementation
void displayMessage() {
    cout << "Welcome to Transflower learning using C++ \n";
}
```

**`src/math.cpp`**
```cpp
#include "math.h"
#include "Math.h"

int addition(int num1, int num2) {
    int result = num1 + num2;
    return result;
}

int subtraction(int num1, int num2) {
    int result = num1 - num2;
    return result;
}

int multiplication(int num1, int num2) {
    int result = num1 * num2;
    return result;
}

int division(int num1, int num2) {
    int result = num1 / num2;
    return result;
}
```

### 4. **Create the Main File**

**`src/main.cpp`**
```cpp
#include <iostream>   //include header file
#include "../include/handler.h"
#include "../include/math.h"

using namespace std;   //import namespace

//Entry Point Function : main
int main()
{
    std::cout << "Hello World!\n";
    displayMessage();  //invoke other function   
    int calculatedValue;   
    calculatedValue = addition(56, 65);  //invoke other function
    cout << "Addition Result=" << calculatedValue;


    calculatedValue = subtraction(34, 15);  //invoke other function
    cout << "Subtraction Result=" << calculatedValue;


    calculatedValue = multiplication(12, 6);  //invoke other function
    cout << "Multiplication Result=" << calculatedValue;


    calculatedValue = division(56, 2);  //invoke other function
    cout << "Division Result=" << calculatedValue;

}


```

### 5. **Compile and Link with MinGW**

**Compiling and Linking Manually:**

1. **Open Command Prompt:**
   Open Command Prompt or a terminal where MinGW's `bin` directory is in your `PATH`.

2. **Navigate to the Project Directory:**
   ```bash
   cd path\to\Basic_Project
   ```

3. **Compile Source Files:**
   Compile each `.cpp` file into an object file (`.o`):
   ```bash
   
g++ -Iinclude -c D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/src/handler.cpp -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/handler.o
g++ -Iinclude -c D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/src/math.cpp -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/math.o
g++ -Iinclude -c D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/src/main.cpp -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/main.o

   ```

   - `-Iinclude` tells the compiler to look for header files in the `include` directory.
   - `-c` tells the compiler to compile source files into object files.

4. **Link Object Files:**
   Link the object files to create the executable:
   ```bash
  
g++ D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/handler.o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/math.o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/main.o -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/basic_project.exe
   ```

5. **Run the Executable:**
   ```bash
   build\basic_project.exe
   ```

**Using a Batch Script:**

You can automate the build process with a batch script. Create a file named `build.bat` in your project directory with the following content:

**`build.bat`**
```bat
@echo off
REM Create build directory if it doesn't exist
if not exist build mkdir build

REM Compile source files
gg++ -Iinclude -c D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/src/handler.cpp -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/handler.o
g++ -Iinclude -c D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/src/math.cpp -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/math.o
g++ -Iinclude -c D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/src/main.cpp -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/main.o

REM Link object files
g++ D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/handler.o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/math.o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/main.o -o D:/Ravi/TAP/TAP/CPP/Solutions/Basic_Project/build/basic_project.exe

echo Build complete.
```

Run the batch script from the command line to compile and link your project:
```bash
build.bat
```

### 6. **Alternative: Using a Makefile**

You can also use a Makefile for managing the build process. Create a `Makefile` in your project directory:

**`Makefile`**
```makefile
CXX = g++
CXXFLAGS = -Iinclude
OBJDIR = build
SRCDIR = src
TARGET = $(OBJDIR)/my_project.exe

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(OBJDIR)\*.o $(TARGET)

.PHONY: all clean
```

To build the project using the Makefile, open Command Prompt or a terminal and run:
```bash
make
```

To clean up the build files, run:
```bash
make clean
```

### Summary

- **Organize Code:** Separate header and source files into `include/` and `src/` directories.
- **Compile and Link:** Use `g++` to compile and link multiple source files.
- **Batch Script or Makefile:** Automate the build process with a batch script or Makefile for convenience.

This approach ensures a well-organized C++ project and simplifies the build process when working with multiple source files using MinGW.