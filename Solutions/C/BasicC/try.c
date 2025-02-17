#include <stdio.h>      //header file
#include <stdbool.h>
//entry point function
int main(){
    //int :data type
    //sum :variable
    int sum;    //variable declartion
    char ch;
    sum=670;    //initialization

    ch='X';

    float unitPrice=34.6f;  //declaration and initialization on one line
    bool status=false;

    //Looping statements
    for(int i=0; i<10;i++){
        printf("\t %d  \t %d  \t %d \t %d  \t %d \t %d  \t %d\n",i, i*2, i*3, i*4, i*5, i*6, i*7);
    }
}
