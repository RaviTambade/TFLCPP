When you're learning C programming, you'll encounter a variety of inbuilt functions that help perform common tasks such as input/output operations, string manipulation, memory management, and mathematical calculations. Below is a list of some commonly required inbuilt C functions that are widely used in C programming:

### 1. **Input/Output Functions**
- **`printf()`**: Used to print output to the console.
  ```c
  printf("Hello, World!\n");
  ```
- **`scanf()`**: Used to take input from the user.
  ```c
  int num;
  scanf("%d", &num);
  ```
- **`getchar()`**: Reads a single character from standard input.
  ```c
  char c = getchar();
  ```
- **`putchar()`**: Outputs a single character to the standard output.
  ```c
  putchar('A');
  ```

### 2. **String Functions**
- **`strlen()`**: Returns the length of a string (excluding the null terminator).
  ```c
  size_t len = strlen("Hello");
  ```
- **`strcpy()`**: Copies a string from source to destination.
  ```c
  char dest[20];
  strcpy(dest, "Hello");
  ```
- **`strcat()`**: Concatenates two strings.
  ```c
  char dest[20] = "Hello ";
  strcat(dest, "World");
  ```
- **`strcmp()`**: Compares two strings.
  ```c
  int result = strcmp("apple", "banana");
  ```
- **`strchr()`**: Finds the first occurrence of a character in a string.
  ```c
  char *ptr = strchr("Hello", 'e');
  ```

### 3. **Mathematical Functions**
- **`abs()`**: Returns the absolute value of an integer.
  ```c
  int abs_value = abs(-5);
  ```
- **`sqrt()`**: Returns the square root of a number.
  ```c
  double result = sqrt(25.0);
  ```
- **`pow()`**: Returns the value of a number raised to the power of another number.
  ```c
  double result = pow(2.0, 3.0); // 2^3 = 8
  ```
- **`sin()`, `cos()`, `tan()`**: Trigonometric functions.
  ```c
  double result = sin(3.14159 / 2); // 1.0
  ```
- **`round()`**: Rounds a floating-point number to the nearest integer.
  ```c
  double result = round(3.6); // 4.0
  ```

### 4. **Memory Management Functions**
- **`malloc()`**: Allocates a block of memory of a specified size.
  ```c
  int *ptr = (int*) malloc(sizeof(int) * 5); // Allocates memory for 5 integers
  ```
- **`calloc()`**: Allocates memory for an array of elements, initializing them to zero.
  ```c
  int *ptr = (int*) calloc(5, sizeof(int)); // Allocates memory for 5 integers, initialized to 0
  ```
- **`free()`**: Frees a previously allocated block of memory.
  ```c
  free(ptr);  // Deallocates the memory
  ```

### 5. **Character Handling Functions**
- **`isdigit()`**: Checks if a character is a digit (0-9).
  ```c
  if (isdigit('5')) {
      printf("It's a digit!\n");
  }
  ```
- **`isalpha()`**: Checks if a character is an alphabet letter (A-Z or a-z).
  ```c
  if (isalpha('A')) {
      printf("It's an alphabet letter!\n");
  }
  ```
- **`toupper()`**: Converts a character to uppercase.
  ```c
  char upper = toupper('a'); // 'A'
  ```
- **`tolower()`**: Converts a character to lowercase.
  ```c
  char lower = tolower('A'); // 'a'
  ```

### 6. **File Handling Functions**
- **`fopen()`**: Opens a file.
  ```c
  FILE *file = fopen("example.txt", "r");
  ```
- **`fclose()`**: Closes a file.
  ```c
  fclose(file);
  ```
- **`fread()`**: Reads data from a file.
  ```c
  fread(buffer, sizeof(char), 100, file);
  ```
- **`fwrite()`**: Writes data to a file.
  ```c
  fwrite(buffer, sizeof(char), 100, file);
  ```
- **`fprintf()`**: Writes formatted data to a file.
  ```c
  fprintf(file, "Hello, World!\n");
  ```
- **`fscanf()`**: Reads formatted data from a file.
  ```c
  fscanf(file, "%d", &num);
  ```

### 7. **Conversion Functions**
- **`atoi()`**: Converts a string to an integer.
  ```c
  int num = atoi("123");
  ```
- **`atof()`**: Converts a string to a floating-point number.
  ```c
  double num = atof("3.14");
  ```
- **`itoa()`**: Converts an integer to a string (not part of the standard library, but can be implemented or found in some compilers).
  ```c
  itoa(123, buffer, 10);  // Converts integer to string in base 10
  ```

### 8. **Time Functions**
- **`time()`**: Returns the current time in seconds since the epoch.
  ```c
  time_t current_time = time(NULL);
  ```
- **`clock()`**: Returns the processor time consumed by the program.
  ```c
  clock_t start_time = clock();
  ```
- **`difftime()`**: Computes the difference in time between two time values.
  ```c
  double diff = difftime(end_time, start_time);
  ```

### 9. **Exit Functions**
- **`exit()`**: Terminates the program with a specified exit status.
  ```c
  exit(0);  // Successful termination
  ```
- **`abort()`**: Abnormally terminates the program.
  ```c
  abort();  // Terminates program immediately
  ```

### 10. **Utility Functions**
- **`sizeof()`**: Returns the size of a data type or object in bytes.
  ```c
  size_t size = sizeof(int);  // Typically 4 bytes
  ```
- **`typeid` (in C++ but not standard in C)**: Used to get the type of a variable at runtime.

These are just some of the most common inbuilt functions in C that you will frequently use while learning and writing programs. There are many other functions available in various C libraries for more advanced operations like networking, multi-threading, and more.