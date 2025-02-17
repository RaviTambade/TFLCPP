#include <stdio.h>
//to check the charcter is digit or not
int main (){
    char ch;
    printf("enter the charcter\n");
    scanf("%c",&ch);
    if( ch>=0 && ch<=9){
        printf("char is digit");
    }else{
        printf("char is not digit");
    }
    return 0;




}