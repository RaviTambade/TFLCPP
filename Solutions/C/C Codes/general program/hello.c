#include <stdio.h>
int main(){
    int stroke ;
    stroke  = 2 ;
    int *ptrstroke=&stroke ;
    *ptrstroke=4; 
    printf(" the value of the stroke is:%d\n",*ptrstroke );
    printf(" the value of the stroke is:%d\n",ptrstroke );
}
