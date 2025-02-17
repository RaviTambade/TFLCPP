#include "stack.h"
#include<stdio.h>

//Learn, Unlearn, Relearn
//Stack Operation Implementation

void push(struct Stack *ptrStack, int data){
    //code implementation
    //
    if(ptrStack->top==4){
        printf("Stack Overflow\n");
        return;
    }
    ptrStack->top=ptrStack->top+1;
    ptrStack->arr[ptrStack->top]=data;
}

int pop(struct Stack *ptrStack){
    //code implementation
    return 0;
}

void display(struct Stack *ptrStack){
    //code implementation

    for(int i=0; i<=ptrStack->top; i++){
        printf("%d\n", ptrStack->arr[i]);
    }
}