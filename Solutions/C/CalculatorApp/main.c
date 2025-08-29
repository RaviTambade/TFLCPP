#include <stdio.h>
#include "./compute/calculator.h"
#include "./graphics/circle.h"
  
//integrate all the reusable functions here in main function
//Entry point of the program

int main(){
    //invoke logic using reusable functions
    int op1=67;
    int op2=123;

    int data1=addition(op1, op2);

    int data2=subtraction(512,12);
    int data3=multiplication(5,3);
    int data4=division(55,5);
    int data5=subtraction(100,99);
    printf("Addition of 56 and 34 is %d\n",data1);
    printf("Subtraction of 512 and 12 is %d\n",data2);
    printf("Multiplication of 5 and 3 is %d\n",data3);
    printf("Division of 55 and 5 is %d\n",data4);

    float area=calculateArea(5);
    float circumference=calculateCicumference(5);
    printf("Area of circle with radius 5 is %f\n",area);
    printf("Circumference of circle with radius 5 is %f\n",circumference);
  
      return 0;
}  


//Command for compilation and creation of exe 
//source files: .\compute\calculator.c .\graphics\circle.c .\main.c

// gcc -I  include .\compute\calculator.c .\graphics\circle.c .\main.c  -o test.exe