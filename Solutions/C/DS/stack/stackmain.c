#include "stack.h"
#include <stdio.h>

int main(){
    extern struct Stack s1;
    s1.top=-1;
    printf("Top value at start= %d\n", s1.top);
    push(&s1, 10);
    printf("Top value at start= %d\n", s1.top);
    push(&s1, 20);
    printf("Top value at start= %d\n", s1.top);
    push(&s1, 30);
    printf("Top value at start= %d\n", s1.top);
    push(&s1, 40);
    printf("Top value at start= %d\n", s1.top);
    push(&s1, 100);
    printf("Top value at start= %d\n", s1.top);
    display(&s1);