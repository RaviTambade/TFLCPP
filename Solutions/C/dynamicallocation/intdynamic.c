#include <stdio.h>
#include <stdlib.h>

int main(){

    int result=99;          // data is kept on Stack (Push)


    int *ptrMarks=NULL;     //declare pointer
    int numberofbytes=sizeof(int);  // calculate number of bytes for integer 

    ptrMarks= (int *)malloc(numberofbytes); //Allocate memory on heap of size integer

    *ptrMarks=88;           //assign value to variable pointed by Pointer

    free(ptrMarks);   //Free memory from heap of size integer



    //dynamic memory allocation for array of int 

    int *ptrPrices=NULL;

    int numberofBytesforPrices= 5 * sizeof(int );
    ptrPrices=(int *) malloc( numberofBytesforPrices);

    int *ptrHead=ptrPrices;

    *ptrPrices=77;
    ptrPrices++;  //move pointer to address next location in heap memory allocated

    *ptrPrices=66;  
    ptrPrices++; //move pointer to address next location in heap memory allocated

    *ptrPrices=55;
    ptrPrices++; //move pointer to address next location in heap memory allocated

    *ptrPrices=44;
    ptrPrices++; //move pointer to address next location in heap memory allocated

    *ptrPrices=33;

    //Start reading data from First element

     for(int i=0; i<5; i++){
       int thePrice= ptrHead[i];
       printf(" %d", thePrice);
     }

     free(ptrHead);
     ptrHead=NULL;

    }