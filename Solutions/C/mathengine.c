#include<stdio.h>
//set of functions implemented 
//write once and use anytime

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

float generateArea(int radius){
  float area=0;
  float pi=3.14f;
  area=pi * radius * radius;
  return area;
}

float generateCicumference(int radius){
  float circumference=0;
  float pi=3.14f;
  circumference=pi * radius * 2;
  return circumference;
}

//write a function to generate factorial of a number given my user as input
// 4 !  = 1 *2 *3*4


int main(){
    //invoke logic using reusable functions
    int data1=addition(56,34);
    int data2=subtraction(512,12);
    int data3=multiplication(5,3);
    int data4=division(55,5);
    int data5=subtraction(100,99);
}