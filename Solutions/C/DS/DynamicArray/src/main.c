
#include<stdio.h>
#include<stdlib.h>
#include "darray.h"

extern int * globalPtr;
  //it is a global pointer variable of type integer
int main(){
  int size=0;
  printf("Welcome to Dynamic array CRUD Operations\n");
  int option=1;
  while(1){
        printf("\n CRUD Operations Menu \n");
        printf("1.Create \t");
        printf("2.Display \t");
        printf("3.Exit\t");
        scanf("%d", &option);
        switch(option){
              case 1:
                printf("Current size of array: %d\n", size);  
                printf(" Option Selected: Insert\n");
                create(globalPtr, &size);
              break;
              case 2:
              {
                printf(" Option Selected: display\n");
                printf("Current size of array: %d\n", size);  
                display(globalPtr, size);
              }
              break;
              case 3:
                printf(" Option Selected: Exit\n");
               return 0;
              default:
                printf(" Invalid Options, Please try again\n");
        }
  }
}