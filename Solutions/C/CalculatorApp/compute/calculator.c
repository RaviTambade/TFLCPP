#include "calculator.h"

int addition(int op1, int op2){
    int result=op1+op2;
    return result;
}

int subtraction(int op1, int op2)
{
    int result=op1-op2;
    return result;
}

int multiplication(int op1, int op2){
    int result=op1*op2;
    return result;
}

int division(int op1, int op2)
{
    int result=op1/op2;
    return result;
}


//Pass by value
void swap(int x, int y){
    //Swapping two numbers (we are swapping actual values)
    //two new varaibles are pushed on stack and values are copied into new varaibles
    int temp=x;
    x=y;
    y=temp;
}

//Pass by address
void calculate(int radius, float * ptrArea, float * ptrCircumference){

    *ptrArea=(3.14)*radius*radius;
    *ptrCircumference=(2)*(3.14)* radius;
}
