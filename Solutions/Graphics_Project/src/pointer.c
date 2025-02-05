#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// variables declared outside of main function are called  global variables
int runs = 670;

//structure
struct Point{
    int x;
    int y;
};


void draw() {
    int timingcount = 6700;
    printf("runs = %d", runs);
}

void display() {
    printf("runs = %d", runs);
}

int main()
{
    //Local variables are variables which are declared within  function scope
    //normal variable stores value
    bool status = false;
    char ch = 'T';
    int  marks = 98;
    float  result=97.5;

    //pointer variable stores address of another variable
    //Pointer is pointing to location of stack where value is stored
    int* ptr1 = &marks;
    int* ptr2 = &marks;
    
    int * ptr = (int *)malloc(sizeof(int));
    printf(" \n Address of ptr =%d",ptr );
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign a value to the allocated memory
    *ptr = 30;

     //What is the real meaning of Pointer ?
    //it is a variable which stores address of another variable
    printf("runs = %d", runs);
    printf("\n marks= %d", marks);
    printf("\n data pointed by ptr1= %d", *ptr1);
    printf("\n data pointed by ptr2= %d", *ptr2);
    printf("\n Address of data= %d", ptr);
    printf("\n data represented by by ptr: %d\n", *ptr); // Outputs: 30
    printf("\n Welome to Transflower\n");

    //Pointer is pointing to location on heap where value is  stored.
    //malloc-----it is c library function
    //this function dynamnically allocates number of bytes on heap for storing 
    //integer value;
    //sizeof ()----------------------
    int intSize=sizeof(int);
    int charSize=sizeof(char);
    int floatSize=sizeof(float);
    int boolSize=sizeof(bool);

    printf(" \n number of bytes needed for data types \n");
    printf(" int %d  , char %d,  float %d, bool %d \n", intSize, charSize, floatSize, boolSize);
    
    //elements are create on stack
    // values are going to be kept  inside stack
    struct  Point startPoint;
    startPoint.x=200;
    startPoint.y=300;
    printf(" \n Point  x=%d  , y=%d   \n", startPoint.x, startPoint.y);
    
    
    //values are going to be kept inside heap
    //elments are created and managed at Heap
     struct Point *ptrPoint = (struct Point *)malloc(sizeof(struct Point));
    if (ptrPoint == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation fails
    }

    ptrPoint->x=45;
    ptrPoint->y=135;

    int sizePoint=sizeof(struct Point);
    printf(" \n Address of  Point = %d   \n", ptrPoint);
    printf(" \n struct Point=  %d bytes \n", sizePoint);
    printf("Point coordinates: x = %d, y = %d\n", ptrPoint->x, ptrPoint->y);

    free(ptr);
    free(ptrPoint);
}

// g++ -o output  pointer.c -l bgi -l gdi32 -l comdlg32 -l uuid -l ole32 -l oleaut32

