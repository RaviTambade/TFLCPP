
//Agenda: Understand concept  Pointer to Pointer in C Prog.
#include <stdio.h>
//Entry Point function
int main(){
    int data=9999;          //an integer variable
    int *ptrData=&data;     //pointer to the variable data
    int **ptrToPtrData=&ptrData;//Pointer to the pointer 'ptrData'
    int ***ptrToPtrToPtrData=&ptrToPtrData;


    printf("Value of Data= %d\n",data);
    printf("Value of ptrData= %d\n", *ptrData);
    printf("Value of ptrOfPtrData= %d\n", **ptrToPtrData);
    printf("Value of ptrOfptrOfPtrData= %d\n", ***ptrToPtrToPtrData);
}