#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int main(){

    //Variable declaration
    bool status=false;
    int sum=567;

    //Pointer to integer variable

    //pointer stores address of integer variable
    int *ptr=NULL;
    //malloc function is used to allocate memory on heap
    //return type of malloc is void pointer
    //typecasting is done to int pointer
    //explicit typecasting
    ptr=(int * )malloc(sizeof(int));
    *ptr=100;
    printf("sum=%d\n", sum);
    printf("*ptr=%d\n", *ptr);
    free(ptr);
    //Reduce warnings from program to save application from crashing
    return 0;
    }