
//Agenda: Understand concept  Pointer to Pointer in C Prog.
#include <stdio.h>
//Entry Point function
int main(){
    int data=9999;          //an integer variable on stack
    int *ptrData=&data;     //pointer to the variable data
    int **ptrToPtrData=&ptrData;//Pointer to the pointer 'ptrData'
    int ***ptrToPtrToPtrData=&ptrToPtrData;

    int * ptrHeapData=(int *) malloc(sizeof(int));
    *ptrHeapData=7777; //On heap
    //array declaration
    int marks[5]={345,65,74,67,55};
    //ptr stores address of first location of array
   
    printf("\nPointer arithmatic\n");

    int * ptr=&marks;
    printf("Value of Data= %d\n",*ptr);
    ptr++;
    printf("Value of Data= %d\n",*ptr);
    ptr--;
    printf("Value of Data= %d\n",*ptr);
   
    


    printf("Value of Data= %d\n",data);
    printf("Value of ptrData= %d\n", *ptrData);
    printf("Value of ptrOfPtrData= %d\n", **ptrToPtrData);
    printf("Value of ptrOfptrOfPtrData= %d\n", ***ptrToPtrToPtrData);

    if(ptrHeapData !=NULL){
        free(ptrHeapData);
    }

}