#include "darray.h"
#include<stdio.h>
#include<stdlib.h>


//Implementation of Reusable functions  CRUD Opertions

extern int *globalPtr;  //it is a global pointer variable of type integer

void  create(int *ptrArr, int *ptrSize){
  int newSize;
  printf("\n Enter the number of elements to add :");
  scanf("%d",&newSize);
  int  sz=*ptrSize+newSize;
  printf("New size of array: %d\n", sz);
  //Allocate memory for new array
  ptrArr= (int *)malloc( sz * sizeof(int));
  if(ptrArr ==NULL){
    printf("Memory allocation failed\n");
    exit(1);
  }

  //Accept input from user for newly created array
  for( int i=0; i< sz; i++){
    printf("Enter element  %d", i+1);
    int number;
    scanf("\t %d", &number);
    ptrArr[i]=number;
  }
  *ptrSize=sz;
  printf("New size of array: %d is created.\n", *ptrSize);
  
  //initialize global pointer variable
  globalPtr=ptrArr;
  }


void display(int *ptrArr, int size){
   printf("Existing Array elments :\n");
   printf("Size of array: %d\n", size);
    for(int i=0; i<size; i++){
      printf("%d \t", ptrArr[i]);
    }
}
