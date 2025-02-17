#include <stdio.h>
//#include "./compute/calculator.h"
//#include "./graphics/circle.h"
  
//Pass by address

void swap(int* x, int* y){
    //Swapping two numbers (we are swapping actual values)
    //two new varaibles are pushed on stack and values are copied into new varaibles
    int temp=*x;
    *x= *y;
    *y=temp;
    printf("\n Inside swap function: swapping values X= %d, Y=%d",*x,*y);
}

//Pass by address
void calculate(int radius, float * ptrArea, float * ptrCircumference){

    *ptrArea=(3.14)*radius*radius;
    *ptrCircumference=(2)*(3.14)* radius;
}


//integrate all the reusable functions here in main function
//Entry point of the program

int main(){
    //invoke logic using reusable functions
    /*int op1=67;
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
    */
    int num1=67;
    int num2=87;
    
    printf("\n Before swapping values num1= %d, num2=%d",num1,num2);
    //pass by value
    //swap(num1, num2);
    //pass by address
    swap(&num1,&num2);
    printf("\n After Swapped values num1= %d, num2=%d",num1,num2);

    int r=25;
    float resultarea,resultCircumference;

    printf("\n Result area = %f", resultarea);
    printf(" Result circumference = %f", resultCircumference);

    //pass by address
    calculate(r, &resultarea, &resultCircumference);
    printf("\nAfter calling ");
    printf("\n Result area = %f", resultarea);
    printf("\n Result circumference = %f", resultCircumference);
    return 0;
}  