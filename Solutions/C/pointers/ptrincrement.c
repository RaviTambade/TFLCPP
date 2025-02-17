#include <stdio.h>

int main(){
    //Array element Traversing using Pointer
    int marks[5]={345,65,74,67,55};
    //ptr stores address of first location of array
   
    printf("\nPointer arithmatic\n");
    int * ptr=&marks;
    printf("Value of Data= %d\n",*ptr);
    ptr++;  //move forward
    printf("Value of Data= %d\n",*ptr);
    ptr--;  //move backward
    printf("Value of Data= %d\n",*ptr);
}