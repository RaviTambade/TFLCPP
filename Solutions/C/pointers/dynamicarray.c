//Problem Statement:
//Perform CRUD Operations using dynamic array of integers.
//Create dynamic array using malloc, free , realloc functions.
//Solving problem:
//Define entry point main function.
//Define pointer which will be used to access, update integer values from

//Dynamic array.
//Dyanice Array: Array size is not fixed.
//Dynamic Array: Memory is allocated at runtime. (using malloc or realloc functions)
//Dynamic Array: Memory is allocated in heap memory.

//Define reusable functions to perform CRUD operations.

#include<stdio.h>
#include<stdlib.h>

//Reusable functions declarations
void create(int **ptrArr, int *ptrSize);
void read(int *ptrArr, int size);
void update(int *ptrArr, int size);
void delete(int *ptrArr, int element);
int search(int *ptrArr, int size, int theElement);

//Entry Point function Implementation
int main(){
  int *ptrArray=NULL;
  int size=0;
  printf("Welcome to Dynamic array CRUD Operations\n");
  int option=1;
  while(1){
        printf("\n CRUD Operations Menu \n");
        printf("1.Create \t");
        printf("2.Read\t");
        printf("3.Update\t");
        printf("4.Delete\t");
        printf("5.Search\t");
        printf("6.Exit\t");
        scanf("%d", &option);

        switch(option){
              case 1:
                printf(" Option Selected: Create\n");
                create(&ptrArray, &size);
              break;
              case 2:
                printf(" Option Selected: Read\n");
                read(ptrArray,size);
              break;
              case 3:
                printf(" Option Selected: Update\n");
              break;
              case 4:
                printf(" Option Selected: Delete\n");
                 delete(ptrArray,size);
              break;

              case 5:
                printf(" Option Selected: Search\n");
                 int element = 30;
                 int result = search(ptrArray, size, element);
                 printf("Element %d found at index %d\n", element, result);
              break;

              case 6:
                printf(" Option Selected: Exit\n");
               return 0;
              default:
                printf(" Invalid Options, Please try again\n");
        }
  }
}

//Implementation of Reusable functions  CRUD Opertions

void create(int **ptrArray, int *ptrSize){
  int newSize;
  printf("\n Enter the number of elements to add :");
  scanf("%d",&newSize);
  *ptrArray= realloc(*ptrArray, sizeof(*ptrSize + newSize)* sizeof(int));

  if(*ptrArray ==NULL){
    printf("Memory allocation failed\n");
    exit(1);
  }

  //Accept input from user for newly created array
  for( int i=*ptrSize; i< *ptrSize + newSize; i++){
    printf("Enter element  %d", i+1);
    scanf("%d", &(*ptrArray)[i]);
  }

  *ptrSize+=newSize;
  printf(" %d elements added. /n");
}

void read(int *ptrArr, int size){
  printf("Array elments\n");
  for(int i=0; i<size;i++){
    printf("%d /t", ptrArr[i]);
  }
  printf("\n");
}

void delete(int *ptrArr, int size){
    if (size <= 0) {
        printf("Array is already empty.\n");
        return;
    }

    // Reduce the size
    (size)--;

    // Reallocate memory to reflect the new size
    ptrArr = (int *)realloc(*ptrArr, (size) * sizeof(int));

    // Check if realloc failed
    if (*ptrArr == NULL && size > 0) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    
    printf("Deleted last element. New size: %d\n", size);
}

int search(int *ptrArr, int size, int theElement) {
    for (int i = 0; i < size; i++) {
        if (ptrArr[i] == theElement) {
            return i;  // Return the index of the found element
        }
    }
    return -1;  // Return -1 if the element is not found
}


