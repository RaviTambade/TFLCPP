#include <stdio.h>
int main(){
    int number;
    printf("Enter number\n ");
    scanf("%d",&number);

    int factorial=1;
    for(int i=1; i<=number;i++){
        factorial=factorial*i;
    }
    printf("\n Factorial %d",factorial);
}